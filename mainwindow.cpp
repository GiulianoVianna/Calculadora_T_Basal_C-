#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_calcular_clicked()
{
/*
    Variaveis recebem dados dos campos de texto do formulário.
*/
    QString peso = ui ->txt_peso ->text();
    QString altura = ui ->txt_altura ->text();
    QString idade = ui ->txt_idade ->text();
    QString ind_atividade = ui ->cb_opcao ->currentText();

/*#############################################################*/

    float atividade;
    float calculo_m;
    float calculo_f;
/*
    Valida o preenchimento obrigatório dos campos do formulário.
*/
    if (peso == ""){
        QMessageBox msgBox;
        msgBox.setText("Favor informar o peso!");
        msgBox.exec();
    }
    else if (altura  == ""){
        QMessageBox msgBox;
        msgBox.setText("Favor informar a altura!");
        msgBox.exec();
    }
    else if (idade  == ""){
        QMessageBox msgBox;
        msgBox.setText("Favor informar a idade!");
        msgBox.exec();
    }
    else if (ind_atividade  == ""){
        QMessageBox msgBox;
        msgBox.setText("Favor informar o nível de atividade!");
        msgBox.exec();
    }
/*###############################################################*/

/*
    Regra para validar dados do checkbox e atribuir valor na variavel atividade.
*/

    if (ind_atividade == "Sedentário"){
        atividade = 1.2;
    }
    else if (ind_atividade == "Levemente ativo"){
        atividade = 1.375;
    }
    else if (ind_atividade == "Moderadamente ativo"){
        atividade = 1.55;
    }
    else if (ind_atividade == "Altamente ativo"){
        atividade = 1.725;
    }
    else if (ind_atividade == "Extremamente ativo"){
        atividade = 1.9;
    }

/*###############################################################*/

/*
 *
    string to float - https://forum.qt.io/topic/134869/type-conversion-from-qstring-to-float-and-double
    float to string - https://forum.qt.io/search?term=float%20to%20string&in=titlesposts

    Fórmula para homens: TMB = fator da taxa de atividade x {66 + [(13,7 x Peso(kg)) + ( 5 x Altura(cm)) – (6,8 x Idade(anos))]}
    Fórmula para mulheres: TMB = fator da taxa de atividade x {655 + [(9,6 x Peso(kg)) + (1,8 x Altura(cm)) – (4,7 x Idade(anos))]}


    Executa o cáculo da Taxa de Metabólica Basal - Masculino e Feminino
*/

    if (peso != "" & altura != "" & idade != "" & ind_atividade != ""){

        float pesos = peso.toFloat();
        float alturas = altura.toFloat();
        float idades = idade.toFloat();

        if (ui -> rd_homem -> isChecked()){
            calculo_m = atividade * (66 + (13.7 * pesos) + (5 *  alturas) - (6.8 * idades));
            ui ->txt_resultado ->setText(QString::number(calculo_m));
        }

        else{
            calculo_f = atividade * (655 + (9.6 * pesos) + (1.8 *  alturas) - (4.7 * idades));
            ui ->txt_resultado ->setText(QString::number(calculo_f));
        }
    }
}

/*################################# FIM ##############################*/
