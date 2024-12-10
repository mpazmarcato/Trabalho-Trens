#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <semaphore.h>

sem_t semaforos [7];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,40,40, ui->horizontalSlider_1->value());
    trem2 = new Trem(2,310,40, ui->horizontalSlider_2->value());
    trem3 = new Trem(3,580,40, ui->horizontalSlider_3->value());
    trem4 = new Trem(4,170,160, ui->horizontalSlider_4->value());
    trem5 = new Trem(5,440,160, ui->horizontalSlider_5->value());

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */

    connect(trem1,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(trem1,SIGNAL(ocupaTrilho(int,int)),SLOT(ocupaTrilho(int,int)));
    connect(trem2,SIGNAL(ocupaTrilho(int,int)),SLOT(ocupaTrilho(int,int)));
    connect(trem3,SIGNAL(ocupaTrilho(int,int)),SLOT(ocupaTrilho(int,int)));
    connect(trem4,SIGNAL(ocupaTrilho(int,int)),SLOT(ocupaTrilho(int,int)));
    connect(trem5,SIGNAL(ocupaTrilho(int,int)),SLOT(ocupaTrilho(int,int)));

    connect(trem1,SIGNAL(desocupaTrilho(int)),SLOT(desocupaTrilho(int)));
    connect(trem2,SIGNAL(desocupaTrilho(int)),SLOT(desocupaTrilho(int)));
    connect(trem3,SIGNAL(desocupaTrilho(int)),SLOT(desocupaTrilho(int)));
    connect(trem4,SIGNAL(desocupaTrilho(int)),SLOT(desocupaTrilho(int)));
    connect(trem5,SIGNAL(desocupaTrilho(int)),SLOT(desocupaTrilho(int)));

    sem_init(&semaforos[0], 0, 0);
    sem_init(&semaforos[1], 0, 0);
    sem_init(&semaforos[2], 0, 0);
    sem_init(&semaforos[3], 0, 1);
    sem_init(&semaforos[4], 0, 0);
    sem_init(&semaforos[5], 0, 1);
    sem_init(&semaforos[6], 0, 0);

    init_trem();
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ocupaTrilho(int id_Trem, int id_Trilho){
    int aux;
    switch (id_Trem) {
    case 1:
        switch (id_Trilho) {
        case 0:
            sem_getvalue(&semaforos[0], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[2], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[0]);
            trem1->setX(trem1->getX() + 10);
            break;
        case 2:
            sem_getvalue(&semaforos[2], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[2]);
            trem1->setY(trem1->getY() + 10);
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (id_Trilho) {
        case 0:
            sem_getvalue(&semaforos[0], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[0]);
            trem2->setX(trem2->getX() - 10);
            break;
        case 1:
            sem_getvalue(&semaforos[1], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[5], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[1]);
            trem2->setX(trem2->getX() + 10);
            break;
        case 3:
            sem_getvalue(&semaforos[3], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[3]);
            trem2->setX(trem2->getX() - 10);
            break;
        case 4:
            sem_getvalue(&semaforos[4], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[3], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[4]);
            trem2->setY(trem2->getY() + 10);
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (id_Trilho) {
        case 1:
            sem_getvalue(&semaforos[1], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[1]);
            trem3->setX(trem3->getX() - 10);
            break;
        case 5:
            sem_getvalue(&semaforos[5], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[1], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[5]);
            trem3->setX(trem3->getX() - 10);
            break;
        default:
            break;
        }
        break;
    case 4:
        switch (id_Trilho) {
        case 2:
            sem_getvalue(&semaforos[2], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[0], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[2]);
            trem4->setY(trem4->getY() - 10);
            break;
        case 3:
            sem_getvalue(&semaforos[3], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[4], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[3]);
            trem4->setX(trem4->getX() + 10);
            break;
        case 6:
            sem_getvalue(&semaforos[6], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[6]);
            trem4->setX(trem4->getX() + 10);
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (id_Trilho) {
        case 4:
            sem_getvalue(&semaforos[4], &aux);
            if(aux == 0){
                break;
            }
            sem_getvalue(&semaforos[5], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[4]);
            trem5->setY(trem5->getY() - 10);
            break;
        case 5:
            sem_getvalue(&semaforos[5], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[5]);
            trem5->setX(trem5->getX() + 10);
            break;
        case 6:
            sem_getvalue(&semaforos[6], &aux);
            if(aux == 0){
                break;
            }
            sem_wait(&semaforos[6]);
            trem5->setX(trem5->getX() - 10);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
};

void MainWindow::desocupaTrilho(int id_Trilho){
    sem_post(&semaforos[id_Trilho]);
};
/*
 * Ao clicar, trens começam execução
 */
void MainWindow::init_trem()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_horizontalSlider_1_valueChanged(int value){
    trem1->setVel(value);
};

void MainWindow::on_horizontalSlider_2_valueChanged(int value){
    trem2->setVel(value);
};

void MainWindow::on_horizontalSlider_3_valueChanged(int value){
    trem3->setVel(value);
};

void MainWindow::on_horizontalSlider_4_valueChanged(int value){
    trem4->setVel(value);
};

void MainWindow::on_horizontalSlider_5_valueChanged(int value){
    trem5->setVel(value);
};
