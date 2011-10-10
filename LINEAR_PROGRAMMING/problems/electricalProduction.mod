/* Problème: Production d'électricité */

/*
 * 3 types de centrales
 * Demandes selon suivant 5 periodes dans la journée
 * Horizon glissant: periode de 18h-24h d'un jour j est suivie par la période
   0h-6h du jour j+1
 * Puissance Maximales et puissances minimale de mise en marche
 * Cout de demarrage de centrales 
 * Cout horraires de base et cout horraires supplémentaires
 * Centrales ne peut être démarrée qu'en début de période
 * L'arrêt ne coute rien 
 * Les centrales en marche doivent pouvoir résister à une augmentation de charge de
   15% 
 */

/* Objectif: Quelles centrales faut-il faire fonctionner dans chaque période 
afin de minimiser le coût total journalier ? */

/* Modélisation du problème */

/* np: Nombre de périodes dans la journée 
 * Demap: Puissance dcemandée par le réseau en période p 
 * Largp: Largeur en heures de la période
 * PMint, PMaxt: Puissance minimale et maximale des centrales 
 * NDist : nombre de centrales disponibles
 * CDemt: Cout de demarrage
 * Cmint: cout horraire de base 
 * CSupt: cout horraire supplementaire  

 * NDemtp: nombre entier des centrales de type t démarrées en début de période p
 * NFontp: nombre entier des centrales de type t fonctionnant en période p, 
   borné par NDist
 * PSuptp: total des mégawatts fournis en plus du minimum par les centrales de
   type t en période p
 */
