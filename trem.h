#ifndef TREM_H
#define TREM_H

#include <QThread>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
    Q_OBJECT
public:
    Trem(int ID, int x, int y, int vel);  //construtor com velocidade variável
    void run();         //função a ser executada pela thread
    void setVel(int value);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    //Cria um sinal
signals:
    void updateGUI(int ID, int x, int y, int vel);
    void ocupaTrilho(int id_Trem, int id_Trilho);
    void desocupaTrilho(int id_Trilho);


private:
    int x;           //posição X do trem na tela
    int y;           //posição Y do trem na tela
    int ID;          //ID do trem
    int vel;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
};

#endif // TREM_H
