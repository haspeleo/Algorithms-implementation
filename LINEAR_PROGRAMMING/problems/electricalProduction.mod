! /* Problème: Production d'électricité */
! 
! /*
!  * 3 types de centrales
!  * Demandes selon suivant 5 periodes dans la journée
!  * Horizon glissant: periode de 18h-24h d'un jour j est suivie par la période
!    0h-6h du jour j+1
!  * Puissance Maximales et puissances minimale de mise en marche
!  * Cout de demarrage de centrales 
!  * Cout horraires de base et cout horraires supplémentaires
!  * Centrales ne peut être démarrée qu'en début de période
!  * L'arrêt ne coute rien 
!  * Les centrales en marche doivent pouvoir résister à une augmentation de charge de
!    15% 
!  */
! 
! /* Objectif: Quelles centrales faut-il faire fonctionner dans chaque période 
! afin de minimiser le coût total journalier ? */
! 
! /* Modélisation du problème */
! 
! /* np: Nombre de périodes dans la journée 
!  * Demap: Puissance dcemandée par le réseau en période p 
!  * Largp: Largeur en heures de la période
!  * PMint, PMaxt: Puissance minimale et maximale des centrales 
!  * NDist : nombre de centrales disponibles
!  * CDemt: Cout de demarrage
!  * Cmint: cout horraire de base 
!  * CSupt: cout horraire supplementaire  
! 
!  * NDemtp: nombre entier des centrales de type t démarrées en début de période p
!  * NFontp: nombre entier des centrales de type t fonctionnant en période p, 
!    borné par NDist
!  * PSuptp: total des mégawatts fournis en plus du minimum par les centrales de
!    type t en période p
!  */

 MODEL Electr

 LET

 np = 5             ! nombre de périodes
 nt = 3             ! nombre de type de centrales

 TABLES

 Larg(np)           ! largeur des heures de la période p
 Dema(np)           ! demande en MW de la période p
 PMin(nt)           ! puissance minimale d'une centrale de type t
 PMax(nt)           ! puissance maximale d'une centrale de type t
 CDem(nt)           ! coup de démarrage d'une centrale de type t
 CMin(nt)           ! coût/h d'une centrale de type t
 CSup(nt)           ! cout/h/MW d'une centrale après PMin(nt)
 NDis(nt)           ! nombre de centrales disponibles de type t 

 DATA

 Larg =  6,  3,  6,  3,  6
 Dema = 15000, 30000, 25000, 40000, 27000
 PMin = 850,1250, 1500
 PMax = 2000, 1750, 4000
 CDem = 2000, 1000, 500
 Cmin = 1000, 2600, 3000
 CSup = 2, 1.3, 3
 NDis = 12, 10, 5

 VARIABLES

 NDem(nt, np)       ! centrales de type t demarrées en debut de periode p
 NFon(nt, np)       ! centrales de type t fonctionnant en periode t 
 PSup(nt, np)       ! puissance au-dela de PMin de tous les centrales de type t

 CONSTARINTS        ! Objectif: minimiser le coût total journalier
                    ! cout total = demarrage + cout puissance minimale + cout puissance supplem

CoutTotal : SUM(p=1:np, t=1:nt) CDem(t) * NDem(t, p) +              &
            SUM(p=1:np, t=1:nt) Larg(p) * CMin(t) * NFon(t, p) +    &
            SUM(p=1:np, t=1:nt) Larg(p) * CSup(t) * PSup(t, p)      $


! definir le nombre de generateurs sur un jour glissant
R1 (p=2:np, t=1:nt) : NDem(t, p) >= NFon(t, p)
R2 (t=1:nt)         : NDem(t, 1) >= Nfon(t, 1) - NFon(t, p - 1)

! Puissance limitée
Lim(t=1:nt, p=1:np) : PSup(t, p) <= ((PMax(t, p) - PMin(t, p)) * NFon(t, p))
! Satisfaction des demandes
SatDemande(p=1:np) : SUM(t=1:nt) PMin(t) * NFon(t, p) + &
                     SUM(t=1:np) PSup(t, p) >= Dema(p)
!Reserve de 15%
Reserve(t=1:nt)   : SUM(t=1:nt) PMax(t) * NFon > 1.15 * Dema(p)

BOUNDS

NFon(t=1:nt, p=1:np) .ui. NDis(t)

END













