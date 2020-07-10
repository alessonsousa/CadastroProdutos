/*
 * Titulo: Trabalho de estrutura de dados
 * Author: Alesson Sousa
 * Github: https://github.com/alessonsousa
 * Created on 6 de Março de 2020, 19:16
 *
 * Trabalho feito na diciplina de estrutura de dados no IFCE-Campus Cedro
 *
 * Desenvolver um caixa comercial com cadastro de
produtos, onde cada produto deve ter nome, preço,
código e quantidade. Deve permitir ainda a venda
de produto, listar os produtos cadastrados e buscar
um produto pelo código.
 *Inicio: 08/03/20
 *Fim: 12/03/20
 */
// BIBLIOTECAS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
#define NUM 30

using namespace std;

//REGISTRO DOS PRODUTOS
struct Produtos
{
    char nomeProduto[40];
    float precoProduto;
    int codigoProduto;
    int quantidadeProduto;

};

//FUNÇÕES
void inicio();
int cadastraProdu(Produtos *Produto,int contProdu);
void listaproduto(Produtos *Produto, int ContProdu);
int buscarProduto(Produtos *Produto, int contProdu);
void vendaProduto(Produtos *Produto, int contProdu);
void imprimi(Produtos Produto);

//FUNÇÃO PRINCIPAL MAIN
int main()
{
    int Dig = 0;
    int contProdu = 0;
    int Posicao = 0;
    Produtos Produto[NUM];
    do
    {

        cout << "\n\t\tOPCOES" << endl;
        cout << "-----------------------------------\n";
        cout << "[1]Venda de Produtos" << endl;
        cout << "[2]Produtos Cadastrados" << endl;
        cout << "[3]Buscar Produtos" << endl;
        cout << "[4]Cadastra Produtos" << endl;
        cout << "[5]Sair" << endl;
        cout << "Escolha a opcao e digite o numero: ";
        cin >> Dig;
        cout << "-----------------------------------\n";
        fflush(stdin);
        system("cls");
        switch (Dig)
        {

        case 1:
            vendaProduto(Produto, contProdu);
            break;
        case 2:
            listaproduto(Produto, contProdu);
            break;
        case 3:
        //POSICÃO ESTA RECEBENDO O VALOR DO RETORNO DE BUSCARPRODUTO
            Posicao = buscarProduto(Produto, contProdu);
            imprimi(Produto[Posicao]);
            break;
        case 4:
            contProdu = cadastraProdu(Produto, contProdu);
            break;
        case 5:
            cout << "\n\n\t\tSair\n\n";
            break;
        }
    }
    while(Dig != 5);
    return 0;
}

//FUNÇÃO DE CADASTRA OS PRODUTOS
int cadastraProdu(Produtos *Produto,int contProdu)
{
    int op, i;
    system("cls");
    cout << "\n\tCadastra Produtos" << endl;
    cout << "------------------------------------\n";
    cout << "Nome do Produto: ";
    cin >> Produto[contProdu].nomeProduto;

    cout << "Codigo do Produto: ";
    cin >> Produto[contProdu].codigoProduto;

    cout << "Preco do Produto:R$";
    cin >> Produto[contProdu].precoProduto;

    cout << "Quantidade do Produto: ";
    cin >> Produto[contProdu].quantidadeProduto;

    system("cls");
    //QUANDO VOCÊ CADASTRA UM PRODUTO O CONTPRODU VAI
    //SOMA MAIS 1 NO CONTPRODU++ E VAI RETORNA O VALOR DE DE CONTPRODU
    contProdu++;
    return contProdu;

}
//FUNÇÃO PARA IMPRIMI OS PRODUTOS BUSCADOS
void imprimi(Produtos Produto)
{

    cout << "\t\tProduto do codigo: " << Produto.codigoProduto << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Produto: " << Produto.nomeProduto << endl;
    cout << "Preco:R$" << Produto.precoProduto << endl;
    cout << "Quantidade: " << Produto.quantidadeProduto << endl;
    cout << "--------------------------------------------------------\n\n";
    system("pause");
    system("cls");
}

//FUNÇÃO DE LISTAR TODOS PRODUTOS CADASTRADO
void listaproduto(Produtos *Produto,int contProdu)
{
    int op;
    do
    {

        system("cls");
        cout << "\t\tProdutos Cadastrados";
        //ESSE FOR ESTA FAZENDO UMA VERIFICAÇÃO I E MENOR QUE CONTPRODU 
        //QUE ESTA SENDO RECEBIDO DE CADASTRAPRODU A QUANTIDADE DE PRODUTOS CADASTRADA
        //PARA RODA FOR 
        //PRODUTO[I] VAI RODA A ATRIBUINDO O VALOR DE I NO VETOR
        for(int i = 0; i < contProdu; i++)
        {
            cout << "\n\n";
            cout << "-----------------------------------------------------\n";
            cout << "Nome do Produto: " << Produto[i].nomeProduto << endl;
            cout << "Codigo do Produto: " << Produto[i].codigoProduto << endl;
            cout << "Preco do Produto:R$" << Produto[i].precoProduto << endl;
            cout << "Quantidade do Produto: " << Produto[i].quantidadeProduto << "\n\n";


        }
        cout << "Volta para o menu [1]SIM: ";
        cin >> op;
        system("cls");
    }
    while(op != 1);
}

//FUNÇÃO DE BUSCAR PRODUTOS PELO CODIGO
int buscarProduto(Produtos *Produto, int contProdu)
{
    int i, Num;
    cout << "Digite o codigo do produto: ";
    cin >> Num;
    for (i = 0; i < contProdu; i++)
    {
        //NA VARIAVEL NUM VAI VERIFICAR SE O CODIGO EXISTE
        //SE NUM FOR IGUAL A O CODIGO VAI RETORNA O VALOR DE I 
        if (Num == Produto[i].codigoProduto)
        {
            return i;
        }
    }
    system("cls");
    //SE O CODIGO NÃO FOR IGUAL ELE VAI RETORNA O -1
    return -1;
}

//FUNÇÃO DE VENDAS DOS PRODUTOS
void vendaProduto(Produtos *Produto, int contProdu)
{
    int ven, total, val;
    cout << "Digite o codigo do produto: ";
    cin >> ven;

    for(int i=0; i < contProdu; i++)
    {
        //VAI VERIFICAR SE O VEN E IGUAL O CODIGO E SE QUANTIDADEPRODUTO E MAIOR DO QUE 0
        //SE FOR VAI MANDA VOCÊ DIGITA A QUANTIDADE DE PRODUTOS VENDIDOS
        if(ven == Produto[i].codigoProduto && Produto[i].quantidadeProduto > 0)
        {
            cout << "Digite a quantidade de produtos vendidos: ";
            cin >> total;
            // VAI VERIFICAR SE A QUANTIDADE DE PRODUTOS DE FOI VENDIDA TEM NO ESTOQUE
            if(Produto[i].quantidadeProduto >= total)
            {
                //SE TIVER A QUANTIDADE VAI TIRA A QUANTIDADE DE PRODUTOS NO ESTOQUE DO QUE FOI VENDIDOS
                Produto[i].quantidadeProduto = Produto[i].quantidadeProduto - total;
                cout << "\n\n\tProduto '" << Produto[i].nomeProduto << "' vendido com sucesso.\n";
                system("pause");
                system("cls");
            }
            else if(Produto[i].quantidadeProduto < total)
            {
                cout << "\n\t\tNao tem essa quantidade de produtos no estoque.\n\n";
                system("pause");
                system("cls");
            }
        }
        else if(ven == Produto[i].codigoProduto)
        {
            cout << "\n\tProduto sem estoque.\n\n";
            system("pause");
            system("cls");
        }
        else
        {

        }
    }
    system("cls");
}
