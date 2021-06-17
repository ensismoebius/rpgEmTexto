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

void FaseGuilda(struct Personagem &p){
    unsigned int escolha = -1;

    while(escolha < 1 || escolha > 2){
        std::cout << "Você está andando pela floresta até que se depara com um recrutamento para magos." << std::endl;
        std::cout << "Então você decide emtrar." << std::endl;
        std::cout << "Ao entrar na guilda um poder foi-lhe consedido:" << std::endl;
        p.forcaMagica = p.forcaMagica + 10;
        std::cout << "Agora você tem uma força Mágica de " << p.forcaMagica << std::endl;
        std::cout << "Um velho mago lhe da as instruções: \n1-Você pode fazer missões, para ganhar orbites \n2-Ou então você pode fazer missões para ganhar intens mágicos." << std::endl;
        std::cin >> escolha;
    }

    if(escolha == 1){
        std::cout << "Você tem duas missões: \n1-caçar um javali que esta atormentando a vila (nivel - facil) \n2-buscar o tesouro na torre do Dragão (nivel - difícil)" << std::endl;
        std::cin >> escolha;

        if(escolha == 1){
            std::cout << "Chegando na vila você se depara com o javali." << std::endl;
            std::cout << "1-espantar \n2-matar." << std::endl;
            std::cin >> escolha;

            if(escolha == 1){
                std::cout << "Você espanta o javali e volta para a guilda dos magos." << std::endl;
                p.creditos = p.creditos + 15;

                mostraStatusDoJogador(p);
                
                FaseGuilda(p);
            }else if(escolha == 2){
                std::cout << "Você golpeia o javali mantando-o" << std::endl;
                p.energia = p.energia - 5;
                p.creditos = p.creditos + 24;

                mostraStatusDoJogador(p);
            }
        }else if(escolha == 2){
            std::cout << "Chegando na torre do dragão você encontra o tesouro com facilidade, mas logo em seguida um tenebroso dragão aparece! " << std::endl;
            std::cout << "Te dando duas opções:\n1-Fugir\n2-Lutar" << std::endl;
            std::cin >> escolha;

            if(escolha == 1){
                std::cout << "Você então decidiu fugir? foi um erro!" << std::endl;
                std::cout << "Você infelizmente tropeça e cai pelas escadas da torre e o dragão atiça fogo pela boca em sua direção. o que você fará agora?" << std::endl;
                std::cout << "1-usar a magia para tentar se defender\n2-tentar se esquivar." << std::endl;
                std::cin >> escolha;

                switch(escolha){
                    case 1:
                        if(p.forcaMagica >= 37){
                            std::cout << "Você conseguiu se defender e consequentemente fez o dragão adormecer e conseguiu sair do torre são e salvo..." << std::endl;
                            std::cout << "Muito bem! Você conseguiu pegar o tesouro!" << std::endl;
                            std::cout << "Você volta para a guilda dos magos." << std::endl;
                            p.creditos = p.creditos + 41;

                            mostraStatusDoJogador(p);
                        }else{
                            std::cout << "Você não tem magia o suficiente e então você morre!" << std::endl;
                        }break;
                    case 2:
                        std::cout << "Você não é rápido o suficiente e então você morre!" << std::endl;
                    break;
                    default:
                        std::cout << "Erro" << std::endl;
                    break;
                }
            }else if(escolha == 2){//lutar com o dragao
                std::cout << "Você escolheu dar o primeiro golpe:\n1-Usar magia para enfrenta-lo\n2-Mudar de ideia e tentar domestica-lo" << std::endl;
                std::cin >> escolha;

                switch(escolha){
                    case 1:
                        if(p.forcaFisica >= 40 && p.forcaMagica >= 30){
                            std::cout << "Você consegue atacar o dragão e corre para se esconder nos vão da torre."<< std::endl;
                            std::cout << "O dragão desnorteado começa a atear fogo em toda parte e começa a vir em sua direção.\nO que você fará agora?"<< std::endl;
                            std::cout << "1-usar a magia para tentar se defender\n2-tentar se esquivar." << std::endl;
                            std::cin >> escolha;

                            switch(escolha){
                                case 1:
                                    if(p.forcaMagica >= 37){
                                        std::cout << "Você conseguiu se defender e consequentemente fez o dragão adormecer e conseguiu sair do torre são e salvo..." << std::endl;
                                        std::cout << "Muito bem! Você conseguiu pegar o tesouro!" << std::endl;
                                        std::cout << "Você volta para a guilda dos magos." << std::endl;
                                        p.creditos = p.creditos + 125;

                                        mostraStatusDoJogador(p);
                                    }else{
                                        std::cout << "Você não tem magia o suficiente e então você morre!" << std::endl;
                                    }return;
                                case 2:
                                    std::cout << "Você não é rápido o suficiente e então você morre!" << std::endl;
                                return;
                                default:
                                    std::cout << "Erro" << std::endl;
                                return;
                            }
                        }else{
                            std::cout << "Você se cansa rápido e não tem forças o suficiente para enfrenta-lo" << std::endl;
                        }
                    case 2:
                        std::cout << "Você tenta domestica-lo porém o dragão se irrita.\nVocê morre!" << std::endl;
                    return;
                    default:
                        std::cout << "Erro" << std::endl;
                    return;
                }
            }
        }return;
    }if(escolha == 2){
        std::cout << "Você tem uma missão: \nIr até o castelo abandonado e pegar a joia do Fim" << std::endl;

        escolha = -1;

        if(escolha == -1){
            std::cout << "No castelo você tem três alternativas\n1-Entrar pela porta da frente\n2-Entrar pelos fundos\n3-Criar sua propia entrada criando um portal" << std::endl;
            std::cin >> escolha;

            switch(escolha){
            case 1:
                std::cout << "Ao entrar pela porta da frente, você cai em uma armadilha e\nVocê morre!" << std::endl;
            return;
            case 2:
                std::cout << "Ao entrar pela porta da frente, você se depara com um caminho suspeito e pode ser perigoso!\nFique atento!" << std::endl;
                std::cout << "1-Para desistir\n2-Para continuar" << std::endl;
                std::cin >> escolha;
                
                if(escolha == 1){
                    std::cout << "Você após procurar muito, desiste e vai embora de mãos vazias" << std::endl;
                    p.energia = p.energia - 20;

                    mostraStatusDoJogador(p);

                }else if(escolha == 2){
                    std::cout << "Você se depara com uma porta...mas ela esta emperrada\1-Ignorar\n2-Tentar abrir" << std::endl;
                    std::cin >> escolha;
                    if(escolha == 1){
                        std::cout << "Você após procurar muito, desiste e vai embora de mãos vazias" << std::endl;
                        p.energia = p.energia - 20;

                        mostraStatusDoJogador(p);
                    return;
                    }else if(escolha == 2){
                        if(p.forcaFisica >= 30){
                             std::cout << "Após muito esforço a porta se abre e você encontra a joia do fim!" << std::endl;
                             std::cout << "Muito bem! Você conseguiu pegar a joia!" << std::endl;
                             p.forcaMagica = p.forcaMagica + 16;

                             mostraStatusDoJogador(p);
                        }else{
                            std::cout << "Você após procurar muito, desiste e vai embora de mãos vazias" << std::endl;
                            p.energia = p.energia - 20;

                            mostraStatusDoJogador(p);
                        }
                    }
                }return;
            case 3:
                if(p.forcaMagica >= 37){
                    std::cout << "Após muito esforço você consegue abrir um portal e na mais pura sorte você encontra a joia do fim!" << std::endl;
                    if(p.forcaMagica >= 45){
                        std::cout << "Com o portal aberto você conseguiu pegar a joia! e sair com tranquilidade!" << std::endl;
                        p.forcaMagica = p.forcaMagica + 16;

                        mostraStatusDoJogador(p);
                    }else{
                        std::cout << "Mas, sua magia não se estabilizou e o portal fechou, e sua magia não é suficiente para abrir outro\nTendo somente uma saida: a porta emperrada!" << std::endl;
                        if(p.forcaFisica >= 30){
                             std::cout << "Após muito esforço a porta se abre e você e você consegue sair!" << std::endl;
                             std::cout << "Muito bem! Você conseguiu pegar a joia e sair são e salvo!" << std::endl;
                             p.forcaMagica = p.forcaMagica + 16;

                             mostraStatusDoJogador(p);
                        }else{
                            std::cout << "Após horas sem saber o que fazer você e você consegue uzar as suas forças magicas para usar a joia do fim e se teletransportar para fora do castelo!\n Porém ao sair, a joia se quebra e você sai de mãos vazias." << std::endl;

                            mostraStatusDoJogador(p);
                        }return;
                    }
                }else{
                    std::cout << "Sua magia não é suficiente para abrir esta passagem" << std::endl;
                }return;
            default:
                std::cout << "Erro" << std::endl;
            return;
            }
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

    FaseGuilda(j);

    mostraStatusDoJogador(j);
}
