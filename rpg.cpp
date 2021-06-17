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
    std::string armamento;
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
    eu.creditos = 38;

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
                p.forcaMagica << " com $" << p.creditos << " orbites" << std::endl;
}

void faseDaCidade(struct Personagem &p){ // &p referencia à struct "Personagem"
    
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
                std::cout << "1-Macarrão (Dá muita energia) - $50\n2-Balinha (Dá pouca energia) - $10" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 50){
                        p.energia += 50;
                        p.creditos -= 50;
                        std::cout << "Foi bom enquanto durou..." << std::endl;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                        std::cout << "Foi rapido..." << std::endl;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    return;
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
        
        std::cout << "1-Não\n2-Espada - $200\n3-Adaga - $25\n4-Arco e flecha - $120" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Bela escolha!" << std::endl;

            if(p.creditos >= 200){
                std::cout << "Muitos cairão por essa lâmina!!" << std::endl;
                p.creditos = p.creditos - 200;
                p.armamento = "Espada";

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Você não merece este tesouro plebeu!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Pelo menos dá para apontar um lápis" << std::endl;

            if(p.creditos >= 25){
                std::cout << "ok..." << std::endl;
                p.creditos = p.creditos - 25;
                p.armamento = "Adaga";

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Saia daqui farrapo!!!" << std::endl;
            }
        }else if(opcao == 4){
             if(p.creditos >= 120){
                 std::cout << "Uhm..." << std::endl;
                p.creditos = p.creditos - 120;
                p.armamento = "Arco e flecha";
                
                mostraStatusDoJogador(p);
             }else{
                std::cout << "Saia daqui seu pobre!" << std::endl;
                }
        }
        }else{
            std::cout << "Vá embora!." << std::endl;
        }
    }


void faseTrapaceiros(struct Personagem &p){ // &p referencia à struct "Personagem"
        unsigned int opcao = -1;

        while(opcao < 1 || opcao > 2){
            std::cout << "Agora tu estás perambulando pelos campos e montanhas até que acidentalmente defronta-se com dois trapaceiros. Tu tens duas opções: " << std::endl;
            std::cout << "1-Indecisão\n2-Fujir" << std::endl;
            std::cin >> opcao;
        }

        if(opcao == 1){
            if(p.armamento == ""){
                std::cout << "Você vai na mão contra os trapaceiros..." << std::endl;
                p.creditos = p.creditos - p.creditos;
                std::cout << "Você foi roubado e agora possui " << "$"<< p.creditos << " orbites"<< std::endl;
                
                if(p.creditos <=5){
                    std::cout << "Você sai andando desanimado, e encontra uma mulher pela qual, deixou cair uma joia no chão." << std::endl;
                    std::cout << "Você tem duas alternativas:" << std::endl;
                    std::cout << "1-Devolver para ela\n2-Roubar a joia" << std::endl;
                    std::cin >> opcao;
                    
                    switch(opcao){
                        case 1:
                            std::cout << "Você grita para a ela e a devolve a joia." << std::endl;
                            std::cout << "Ela muito agradescida lhe-da uma recompensa de $26 orbites" << std::endl;
                            p.creditos = p.creditos + 26;
                            
                            mostraStatusDoJogador(p);
                            
                            std::cout << "Então tu poderá voltar para a cidade ou continuar vossa jornada..." << std::endl;
                            std::cout << "1-voltar para a cidade\n2-continuar jornada" << std::endl;
                            std::cin >> opcao;
                            
                            if(opcao == 1){
                                faseDaCidade(p);
                            }else if(opcao == 2){
                                std::cout << "Tu continuas vosso caminho..." << std::endl;
                            }return;
                        case 2:
                            std::cout << "Você pega a joia e vai para um comércio." << std::endl;
                            std::cout << "O vendedor te olha e pergunta: O que tens para mim meu jovem ?" << std::endl;
                            std::cout << "Tu mostra para ele a joia e o comerciante te faz duas ofertas:" << std::endl;
                            std::cout << "1-Compro esta joia de ti por $30 Orbites\n2-Compro esta joia de ti por uma poção de Força Mágica" << std::endl;
                            std::cin >> opcao;
                            if(opcao == 1){
                                p.creditos = p.creditos + 30;
                                
                                mostraStatusDoJogador(p);
                                
                                std::cout << "Então tu poderá voltar para a cidade ou continuar vossa jornada..." << std::endl;
                                std::cout << "1-voltar para a cidade\n2-continuar jornada" << std::endl;
                                std::cin >> opcao;
                                
                                if(opcao == 1){
                                    faseDaCidade(p);
                                }else if(opcao == 2){
                                    std::cout << "Tu continuas vosso caminho..." << std::endl;
                                }return;
                                
                            }else if(opcao == 2){
                                p.forcaMagica = p.forcaMagica + 9;
                                
                                mostraStatusDoJogador(p);
                                
                                std::cout << "Então tu poderá voltar para a cidade ou continuar vossa jornada..." << std::endl;
                                std::cout << "1-voltar para a cidade\n2-continuar jornada" << std::endl;
                                std::cin >> opcao;
                                
                                if(opcao == 1){
                                    faseDaCidade(p);
                                }else if(opcao == 2){
                                    std::cout << "Tu continuas vosso caminho..." << std::endl;
                                }return;
                                
                            }break;
                        default:
                            std::cout << "Erro" << std::endl;
                        break;
                    }
                }
                
            }else{
                std::cout << "Tu sacas vosso(a) " << p.armamento << " e intimida os trapaceiros" << std::endl;
                std::cout << "Eles não se intimidam e partem para cima. Tu tens a oportunidade de matá-los, o que tu farás?" << std::endl;
                std::cout << "1-Os Matarei\n2-Os Imobilizarei" << std::endl;
                std::cin >> opcao;

                if(opcao == 2){
                    opcao = 0;

                    while(opcao < 1 || opcao > 2){
                        std::cout << "A partir de qual parte do corpo desejas tu imobilizar os dois trapaceiros?" << std::endl;
                        std::cout << "1-A partir da cabeça\n2-A partir das pernas" << std::endl;
                        std::cin >> opcao;

                        switch(opcao){
                            case 1:
                                if(p.forcaFisica >= 30){
                                    p.energia -= 70;
                                    p.creditos -= 20;
                                    std::cout << "Você os imobilizou e continuou a vossa jornada" << std::endl;
                                }else{
                                    std::cout << "Desculpe, mas não dá..." << std::endl;
                                }break;
                            case 2:
                                if(p.forcaFisica >=15){
                                    p.energia += 50;
                                    p.creditos -= 10;
                                    std::cout << "Você os imobilizou e continuou a vossa jornada" << std::endl;
                                }else{
                                    std::cout << "Desculpe, mas não dá..." << std::endl;
                                }break;
                            default:
                                std::cout << "Erro" << std::endl;
                            break;
                        }
                        return;
                    }
                }else if(opcao == 1){
                    std::cout << "Preparem-se para morrerem, indolentes!!!" << std::endl;
                    p.energia = p.energia - p.energia;
                    std::cout << "Eles morrem e tu continuas vosso caminho..." << std::endl;
                    return;
                }else{
                    std::cout << "Não farás nada? (...)";
                    return;
                }
            }
        }if(opcao == 2){
            std::cout << "Você então decidiu fujir? foi um erro!" << std::endl;
            std::cout << "Você infelizmente tropeça e é capturado pelos dois trapaceiros. O que farás agora?" << std::endl;
            
            std::cout << "1-Pedir redenção\n2-Escapar\n3-Tentar matá-los" << std::endl;
            std::cin >> opcao;

            if(opcao == 1){
                std::cout << "Eles nunca lhe darão redenção!" << std::endl;
            }else if(opcao == 3){
                std::cout << "Você sorrateiramente puxa uma faquinha escondida em suas vestes, infelizmente um trapaceiro percebe e te nocauteia" << std::endl;

                if(p.energia >= 60){
                    std::cout << "Você perdeu 60 pontos de energia!..." << std::endl;
                    p.energia = p.energia - 60;

                    mostraStatusDoJogador(p);
                }else{
                    std::cout << "Você infelizmente morreu!!!" << std::endl;
                }
            }else if(opcao == 2){
                std::cout << "Ao fugir, você chega até um desfiladeiro, um local sem saida, escorrega e cai..." << std::endl;
            }else{
                std::cout << "Não fará nada?" << std::endl;
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

    faseTrapaceiros(j);

    mostraStatusDoJogador(j);
}
