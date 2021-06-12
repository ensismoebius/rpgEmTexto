#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>


struct Personagem{
    std::string nome;

    unsigned int mana;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Bem vindo ao Hyako Secret Room!\n";
    std::cout << "Voce esta em um mundo onde a ficção é a realidade, \n";
    std::cout << "Com isso o mundo esta sobre ameaça de um ser poderoso chamado Leno Brega\n";
    std::cout << "ele busca migrar o reino de hyako para sua coleção de planetas no sistema solar de bueno...\n";

    std::cout << "nós de hyako secret room somos seres poderosos,porem ainda não podemos contra Leno brega\n";
    std::cout << "Por isso te convocamos aqui neste mundo,sabemos que voce podera nos ajudar...\n";
    std::cout << "Voce é a nossa unica salvação,nos diga quem é voce.\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sr."<< nome <<"!\n";

    struct Personagem eu;

    eu.nome = nome;
    eu.mana = (geraAleatorio() * 50) + 20;
    eu.altura = geraAleatorio() * 200;
    eu.forcaFisica = geraAleatorio() * 200;
    eu.forcaMagica = geraAleatorio() * 100;
    eu.creditos = 30;

    return eu;
}

void mostraStatusDoJogador(struct Personagem &p){

    if(p.mana == 0){
        std::cout << "!!!Você esta morto porque o vendedor não foi com sua cara!!!" << std::endl;
        return;
    }

    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.mana << " de mana com uma força de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " Figuras $" << p.creditos << std::endl;
}

void faseDaCidade(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "voce está no quarto principal do reino, neste quarto voce ve duas portas: Uma porta te levara até a tenda e a outra porta te levara até uma loja de equipamentos.\n Que porta voce escolhera?" << std::endl;
        std::cout << "1-Tenda\n2-Loja de equipamentos" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;
        
        std::cout << "1-Nada\n2-Comida\n3-esferas do dragão" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Bife Acebolado (Dá muita mana)\n2-Banana Frita (Dá pouca mana)" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 50){
                        p.mana += 50;
                        p.creditos -= 50;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.mana += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Esqueci,elas não estão a venda!!!" << std::endl;
            p.mana = p.mana - p.mana;
            return;
        }else{
            std::cout << "mas que sujeito estranho....";
        }

    }

    if(opcao == 2){
        std::cout << "O vendedor te pergunta: Pronto pra Descer o sarrafo em geral?" << std::endl;
        
        std::cout << "1-Não rapai\n2-kamado nichirin\n3-Death Note" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Você tem bons olhos,porem não tem figuras suficientes inbecil" << std::endl;

            if(p.creditos >= 200){
                std::cout << "Muitos Onis cairão por essa Katana!!" << std::endl;
                p.creditos = p.creditos - 200;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Você não merece esta Katana,domine sua respiração primeiro!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Quem diria,agora vou mostrar o novo mundo para Leno Brega!" << std::endl;

            if(p.creditos >= 25){
                std::cout << "Muito bem..." << std::endl;
                p.creditos = p.creditos - 25;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Vaza daqui Fracote!!!" << std::endl;
            }
        }else{
            std::cout << "MORRA!." << std::endl;
        }
    }
}

int main(int argc, char** argv)
{
    
    std::srand(std::time(nullptr)); 

    struct Personagem j = boasVindasDoJogo();

    std::cout << "Você recebeu um presente da divindade Arcon!\n";
    std::cout << "Guarde em sua mente que com grandes poderes vem grandes responsabilidades!\n";

    mostraStatusDoJogador(j);

    faseDaCidade(j);

    mostraStatusDoJogador(j);
}