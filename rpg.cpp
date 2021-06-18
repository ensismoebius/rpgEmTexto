#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// TODO Fazer uma forma do jogador ou jogadora escolher sua raça
// TODO Sendo que cada raça tem a possibilidade de  ter mais ou menos atributos que as outras

struct Personagem{
    std::string nome;

    unsigned int energia;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Boas vindas ao nosso mundo!\n";
    std::cout << "Um sentimento de obscuridade tomou conta de nossa terra, \n";
    std::cout << "o rei Demônio dominou as principais forças de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanças decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e não conseguimos nos defender\n";
    std::cout << "precisamos de alguém que nos lidere para a derrocada deste maldito!\n";
    std::cout << "Você é nossa escolha!! E... a propósito... qual é mesmo o seu nome?\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sir " << nome << "!\n";

    struct Personagem eu;

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;

    return eu;
}

void mostraStatusDoJogador(struct Personagem &p){

    if(p.energia == 0){
        std::cout << "Você morreu!!!" << std::endl;
        return;
    }

    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma força de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaFloresta(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "Você está na floresta, a sua frente tem dois caminhos com neblina, no da direita parece que é possível ver uma cabana, no esquerdo, considerando que há mais neblina, é possível que tenha alguma fonte de água.\nPara onde você deseja ir?" << std::endl;
        std::cout << "1-Direita\n2-Esquerda\n3-Retornar a fase da cidade" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "É mesmo uma cabana abandonada, olhe...há uma fada em um pote, ajudê-a, quem sabe ela possa te recompensar.\nFada diz: Obrigada por me libertar guerreiro, o que posso fazer por você como forma de agradecimento?" << std::endl;
        
        std::cout << "1-Nada, fico feliz por tê-la ajudado\n2-Preciso de uma arma mais forte\n3-Dê-me mais energia" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Uma espada flamejante \n2-um escudo congelante" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao)
            {
                case 1:
                        std::cout << "Fada diz: Ótima escolha, isso lhe ajudará a acabar com aqueles que cruzarem seu caminho." << std::endl;
            
                break;
                
            
                case 2:
                        std::cout << "Fada diz: Muito bem, aqui está o escudo que te protegerá contra seus combatentes." << std::endl;
            
                  break; 
            }
            return;

        }else if(opcao == 3){
            std::cout << "Fada diz: Posso lhe conceder mais 5 pontos de energia." << std::endl;
            p.energia = p.energia + 5;
            return;
        }else{
            std::cout << "Fada diz: Muito obriga por me libertar, você salvou a minha vida, desejo-lhe sorte em sua missão!" << std::endl;
        }

    }

    if(opcao == 2){
        std::cout << "Está difícil enxergar com tanta neblina, mas parece mesmo um lago, o que deseja fazer?" << std::endl;
        
        std::cout << "1-Retornar para a floresta \n2-Atravessar a nado \n3-Usar força mágica para se transportar para o outro lado do lago" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Para esta missão é necessária uma força física mínima de intensidade 15." << std::endl;

            if(p.forcaFisica >= 15){
                std::cout << "Sua força física atual é de: " <<p.forcaFisica<< "\nVocê será capaz de atravessar!!" << std::endl;
                p.forcaFisica = p.forcaFisica - 15;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Sua força física atual é de: " <<p.forcaFisica<< "\nVocê não possui força física suficiente para esta missão!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Para esta missão é necessária uma força mágica mínima de 30 orbites." << std::endl;

            if(p.forcaMagica >= 30){
                std::cout << "Sua força mágica atual é de: " <<p.forcaMagica<< "\nVocê será capaz de atravessar!!" << std::endl;
                p.forcaMagica = p.forcaMagica - 30;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Sua força mágica atual é de: " <<p.forcaMagica<< "\nVocê não possui força mágica suficiente para esta missão!!" << std::endl;
            }
        }else{
            std::cout << "Parece que alguém aqui ficou com medinho!" << std::endl;
        }
    }
}

int main(int argc, char** argv)
{
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();

    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);

    faseDaFloresta(j);

    mostraStatusDoJogador(j);
}
