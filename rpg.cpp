#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// TODO Fazer uma forma do jogador ou jogadora escolher sua raça

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

void faseDaCidade(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "Você está na rua principal da cidade, nesta rua você vê dois estabelecimentos: Uma quitanda de um lado uma loja de armas do outro.\n Para onde você deseja ir?" << std::endl;
        std::cout << "1-Quitanda\n2-Loja de armas" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;
        
        std::cout << "1-Nada\n2-Comida\n3-Que vá para a p*" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Macarrão (Dá muita energia)\n2-Balinha (Dá pouca energia)" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 50){
                        p.energia += 50;
                        p.creditos -= 50;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Prepare-se para morrer indolente!!!" << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "Que cara estranho....";
        }

    }

    if(opcao == 2){
        std::cout << "O vendedor te olha e pergunta: Pronto pra batalha?" << std::endl;
        
        std::cout << "1-Não\n2-Espada\n3-Adaga" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Bela escolha!" << std::endl;

            if(p.creditos >= 200){
                std::cout << "Muitos cairão por essa lâmina!!" << std::endl;
                p.creditos = p.creditos - 200;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Você não merece este tesouro plebeu!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Pelo menos dá para apontar um lápis" << std::endl;

            if(p.creditos >= 25){
                std::cout << "ok..." << std::endl;
                p.creditos = p.creditos - 25;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Saia daqui farrapo!!!" << std::endl;
            }
        }else{
            std::cout << "Vá embora!." << std::endl;
        }
    }
}
void faseDaFloresta(struct Personagem &p){
    
    unsigned int opcao = -1;

    while(opcao < 1 || opcao > 2 ){
        std::cout << "Heroi... O rei demonio esta esperando por voce na cidade caida Lore! " << std::endl;
        std::cout << "Antes de poder confronta-lo, voce precisara� passar pela floresta obscura e derrotar as criaturas malignas que nela habitam.\n\n";

        std::cout << "Voce esta na entrada da floresta, nessa entrada h� dois estabelecimentos:\n\n1-Centro de treinamento\n2-Magic Shoppe\n3-Nada" << std::endl;
        std::cin >> opcao;
        
    }

    if(opcao == 1){
        std::cout << "Salve bravo aventureiro! Eu sou mazumi um mago guerreiro." << std::endl;
        std::cout << "Quer aprender as habilidades que posso te ensinar?" << std::endl;
        std::cout << "Muito bem." << std::endl;
        std::cout << "Se voce VIVER durante minhas aulas, voce pode apenas me agradecer!\n" << std::endl;
    
        std::cout << "1-Mago\n2-Guerreiro\n3-Nada\n\n" << std::endl;
        std::cin >> opcao;
    
        if(opcao == 1){
        
            if(p.creditos >= 1){
                std::cout << "Parabéns, voc� adquiriu a Classe Mago, com ela se pode pegar as energias misticas do mundo ao seu redor e enviar fogo e gelo pelo campo de batalha!\n\n" << std::endl;
                p.creditos = p.creditos - 2;

                mostraStatusDoJogador(p);
                
            }else{
                std::cout << "Você não possui créditos o suficiente." << std::endl;
            }

        }else if(opcao == 2){
            
           if(p.creditos >= 1){
                std::cout << "Parabéns, voc� adquiriu a Classe Guerreiro, com  ela se pode ter um grande engajamento em combates corpo a corpo!\n\n" << std::endl;
                p.creditos = p.creditos - 2;

                mostraStatusDoJogador(p);
                
            }else{
                std::cout << "Você não possui créditos o suficiente." << std::endl;
            }

        }else{
            std::cout << "Que cara estranho....";
        }

    }
    //Division
    if(opcao == 2){
        std::cout << "Eu sou o Warlic, bem-vindo a minha loja de magia! Sinta-se a vontade para examinar minha colecao requintada de itens magicos e pocoes." << std::endl;
        
        std::cout << "1-Nada\n2-Poc�es\n3-Armamento" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;
 
            while(opcao < 1 || opcao > 2){
                std::cout << "1-Po��o f�sica (Aumenta forca)\n2-Po��o magia (Aumenta a forca magica)" << std::endl;
                std::cin >> opcao;
            }
 
            switch(opcao){
                case 1:
                    if(p.creditos >= 2){
                        p.forcaFisica += 10;   
                        p.creditos -= 2;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 1){
                        p.forcaMagica += 10;
                        p.creditos -= 1;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            opcao = 0;
 
            while(opcao < 1 || opcao > 2){
                std::cout << "1-Holy avenger - Espada m�gica forjada com sangue de deuses, qualquer coisa que estre na frente de seu fio � destruido instantaneamente, sem direito a testes de resist�ncia.\n" << std::endl;
                std::cout << "2-super nova bow - Arco que tem a energia de uma estrela concentrada em s�, suas flechas evapora o que toca.\n";
                std::cin >> opcao;
            }
 
            switch(opcao){
                case 1:
                std::cout << "Otima escolha guerreiro!\n\n";
                    if(p.creditos >= 2){
                        p.forcaFisica += 200;   
                        p.creditos -= 2;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                std::cout << "Otima escolha guerreiro!\n\n";
                    if(p.creditos >= 1){
                        p.forcaMagica += 200;
                        p.creditos -= 1;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;
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

    faseDaCidade(j);

    mostraStatusDoJogador(j);
    
    faseDaFloresta(j);
}
