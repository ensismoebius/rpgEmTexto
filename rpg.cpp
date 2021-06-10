#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */


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
    std::cout << "o rei DemÃ´nio dominou as principais forÃ§as de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanÃ§as decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e nÃ£o conseguimos nos defender\n";
    std::cout << "precisamos de alguÃ©m que nos lidere para a derrocada deste maldito!\n";
    std::cout << "VocÃª Ã© nossa escolha!! E... a propÃ³sito... qual Ã© mesmo o seu nome?\n";

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
        std::cout << "VocÃª morreu!!!" << std::endl;
        return;
    }

    std::cout << "VocÃª agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma forÃ§a de intensidade " <<
                p.forcaFisica << " e um poder mÃ¡gico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaCaverna(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "Você chegou na floresta e possui duas cavernas. Tem que decidir em qual entrar." << std::endl;
        std::cout << "1-Caverna Verde\n2-Caverna Azul" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "Quando você entra possui dois baús e precisa escolher apenas uma." << std::endl;
        
        std::cout << "1-Detona\n2-Fraco\n3-Nenhum Baú" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Machado você possuirá maior resistencia\n2-Lança você terá um ataque potenteroso." << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 10){
                        p.energia += 30;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas necessita de mais créditos." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas necessita de mais créditos." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Toma vergonha e escolha algo." << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "Volte quando souber o que deseja.";
        }

    }

    if(opcao == 2){
        std::cout << "Quando você entra possui dois baús e precisa escolher apenas uma." << std::endl;
        
        std::cout << "1-Fino Trato\n2-Gostosura\n3-Nenhum Baú" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Faca você possuirá maior resistencia\n2-Porrete você terá um ataque potenteroso." << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 10){
                        p.energia += 30;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas necessita de mais créditos." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas necessita de mais créditos." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Toma vergonha e escolha algo." << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "Volte quando souber o que deseja.";
        }
    }
}

int main(int argc, char** argv)
{
    // s = seed rand = aleatÃ³rio                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();

    std::cout << "VocÃª recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);

    faseDaCidade(j);

    mostraStatusDoJogador(j);
}
