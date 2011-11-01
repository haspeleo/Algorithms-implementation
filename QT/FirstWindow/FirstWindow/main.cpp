/*
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 1 novembre 2011, 16:37
 */


#include <QApplication>
#include <QPushButton>

int main ( int argc, char *argv[]) {

    QApplication app (argc, argv);
//    QWidget fenetre;
//    fenetre.setFixedSize(400, 250);
//
    QPushButton bouton ("Hello, Qt App");
    //QPushButton bouton ("Hello, Qt App", &fenetre);
    //    bouton.setFont(QFont("Courrier", 14));


    bouton.setText("Pimp my Button !!");

//    bouton.setToolTip("Texte d'aide");
//    bouton.move(60, 50);

    bouton.show();

    return app.exec();
}


