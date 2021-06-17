#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <clocale>

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
    struct InimigosGelidos{
        std::string nome;
        unsigned int dano;
        unsigned int vidaFofo;
        unsigned int danoFofo;
        unsigned int dinheiro;
        unsigned int vidaP;
        unsigned int danoM;
        unsigned int vidaM;
        unsigned int veneno;
    };

    struct InimigosGelidos faseFlorestaGelida(){

        struct InimigosGelidos g;
        g.danoFofo = (geraAleatorio() * 20) + 1000;
        g.dano = geraAleatorio() * 80;
        g.dinheiro = geraAleatorio() * 50;
        g.vidaFofo = (geraAleatorio() * 50) + 1000;
        g.vidaP = (geraAleatorio() * 90) + 10;
        g.danoM = geraAleatorio() *50;
        g.vidaM = (geraAleatorio() * 90) + 200;
        g.veneno = 7;
        return g;
    };


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

void faseFlorestaGelida(struct Personagem &p, struct InimigosGelidos &g){

    std::cout << "Logo apos adquirir o -artefato magico-, nosso proximo destino sera a Floresta Gelida, o lar da pena de uma Fenix Glacial," << std::endl;
    std::cout << "que possui poderes magicos de bencaos, no qual me protegeria das criaturas da Floresta de Nederviersel." << std::endl;
    
    unsigned int opcao = 0;
    unsigned int esc;
    unsigned int luta = 0;

    while(opcao < 1 || opcao > 3){
        std::cout << "Na entrada da floresta, ouvimos um som aterrorizador vindo do seu interior." << std::endl;
        std::cout << "Diz a lenda, que uma criatura perversa e gigantesca perambula por entre as arvores esguias, se escondendo na densa névoa causada pelo gelo." <<  std::endl;
        std::cout << "Ao adentrar na nevoa, percebo alguns vultos ao meu redor, que vao tomando forma de pequenas criaturas fofinhas." << std::endl;
        std::cout << "Ao observar sua fisionomia, decido qual sera minha atitude.\n" << std::endl;
        std::cout << "1 - Atacar \n2 - Deixar elas em paz \n3 - Tentar um contato amigavel" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "Empunho minha arma e desfiro um golpe contra a criatura fofinha que se enfurece e me ataca, causando um dano fatal." << std::endl;
            if(g.danoFofo > 0){
                std::cout << "Voce sucumbiu a investida de uma fera fofuxa." << std::endl;
            }return;
    }

    if(opcao == 2){
        std::cout << "Apos deixar as ferinhas em paz, caminho sem rumo na esperança de encontrar o item sagrado." << std::endl;
        std::cout << "Vagueio por horas ate avistar o que poderia ser uma preguica das neves gigante, com vida de " << g.vidaP << " e dano de " << g.dano << " que logo nota minha presença e vem em minha direcao." << std::endl;
        std::cout << "-Pense rapido heroi-." << std::endl;
        
        std::cout << "1-Enfrentar\n2-Esconder\n3-Fugir" << std::endl;
        std::cin >> esc;

        switch(esc){
            case 1:
                if(p.forcaFisica > g.vidaP){
                    std::cout << "Derrubei essa preguica com um unico golpe." << std::endl;
                    p.creditos = p.creditos + g.dinheiro;
                    p.forcaFisica = p.forcaFisica + 10;
                    p.forcaMagica = p.forcaMagica + 5;
                    mostraStatusDoJogador(p);
                    std::cout << "Depois de derrubar o monstro, recolho os espolios e sigo meu caminho em direcao ao item sagrado." << std::endl;
                    std::cout << "Depois de muito tempo, chegamos a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
                    std::cout << "Essa luz, A Pena de Fenix de Gelo, bem na minha frente." << std::endl;
                    std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
                    std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
                    std::cout << "Ela se aproxima e uma luta começa pela posse do item sagrado" << std::endl;
                    std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;

                }else if(p.forcaFisica < g.vidaP){
                    std::cout << "A preguica me machucou " << std::endl;
                    p.energia = p.energia - g.dano;
                    if(g.dano > p.energia){
                        std::cout << "Fui atropelado e morri." << std::endl;
                        return;
                    }else{
                        p.energia = p.energia - g.dano;
                        std::cout << "Fui atropelado e nao morri." << std::endl;
                        std::cout << "A Preguica continuou correndo sem direcao me deixando no chao com " << p.energia << " de vida, mesmo assim eu rapidamente, sem exitar, me levanto e continuo minha jornada." << std::endl;
                        std::cout << "Depois de muito tempo, cheguei a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
                        std::cout << "Essa luz, A Pena de Fenix de Gelo, bem na minha frente." << std::endl;
                        std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
                        std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
                        std::cout << "Ela se aproxima e uma luta começa pela posse do item sagrado" << std::endl;
                        std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl; 
                    }
                }else{
                    std::cout << "Batemos a cabeca e cada um foi para o seu lado sem dano." << std::endl;
                    std::cout << "Depois de me recuperar da colisao, ainda tonto, segui em frente na minha jornada." << std::endl;
                    std::cout << "Depois de muito tempo, cheguei a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
                    std::cout << "Essa luz, A Pena de Fenix de Gelo, bem na minha frente." << std::endl;
                    std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
                    std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
                    std::cout << "Ela se aproxima e uma luta começa pela posse do item sagrado" << std::endl;
                    std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;
                }break;
            case 2:
                std::cout << "Desesperado vendo a preguiça vindo na minha direção, olho para os lados na procura de algum lugar para esconder." << std::endl;
                std::cout << "Quandoa avisto uma arvore antiga oca, decido me esconder" << std::endl;
                std::cout << "Espio pra ver se a preguica que carinhosamente apelidei de Sidnice, como nao avisti ela nas proximidades, saio do tronco e continuo minha viagem." << std::endl;
                std::cout << "Depois de muito tempo, cheguei a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
                std::cout << "Essa luz, A Pena de Fenix de Gelo, bem na minha frente." << std::endl;
                std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
                std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
                std::cout << "Ela se aproxima e uma luta começa pela posse do item sagrado" << std::endl;
                std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;
                break;
            case 3:
                std::cout << "Sem saber o que fazer, decido fugir dessa investida correndo na direção oposta." << std::endl;
                std::cout << "Depois de muito correr, sem conseguir perder a vista do monstro, por um descuido, não vejo um abismo na minha frente e acabo caindo no limbo," << std::endl;
                std::cout << "me perdendo an escuridão e morrendo na queda." << std::endl;
                p.energia = p.energia - p.energia;
                return;
            default:
                std::cout << "A Preguica nao vai ficar correndo no mesmo lugar esperando voce se decidir, DECIDE LOGO.\n Demorou, voce morreu por ser lerdo demais." << std::endl;
                return;
        }
    }
    if(opcao == 3){
            std::cout << "Me deparando com aquelas criaturas que se parecem com coelhos felpudos, tento um contato mais amigavel." << std::endl;
            std::cout << "Feito esse contato com sucesso, percebo que elas nao sao tao assustadoras quanto pensei, se tornando bem doceis, " << std::endl;
            std::cout << "Eu acho que eles gostaram de mim, mas começam a correr em uma direcao." << std::endl;
            std::cout << "Sem entender nada, começo a segui-los incansavelmente atraves da floresta." << std::endl;
            std::cout << "Depois de muito tempo, chegamos a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
            std::cout << "Essa luz, A Pena de Fenix Glacial, bem na minha frente, nao acredito que os monstrinhos me trouxera ate aqui." << std::endl;
            std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
            std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
            std::cout << "Murilo de Gelo se aproxima e uma luta começa pela posse do item sagrado" << std::endl;
            std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;
    }
        do{
            std::cout << "O que deseja fazer? \n1 - Ataque Fisico\n2 - Ataque Magico \n3 - Defender" << std::endl;
            std::cin >> luta;
        switch(luta){
            case 1:
                if(g.vidaM < p.forcaFisica){
                g.vidaM = 0;
                }else{
                    g.vidaM = g.vidaM - p.forcaFisica; 
                    std::cout << "O Boss esta com " << g.vidaM << " de vida restante." << std::endl;
                }
                
                break;
            case 2:
                if(g.vidaM < p.forcaMagica){
                g.vidaM = 0;
                }else{
                    g.vidaM = g.vidaM - p.forcaMagica;
                    std::cout << "O Boss esta com " << g.vidaM << " de vida restante." << std::endl;
                }break;
            case 3:
                if(p.energia < g.danoM){
                    p.energia = 0;
                }else{
                    p.energia = (p.energia - g.danoM) - g.veneno;
                    std::cout << "Voce esta com " << p.energia << " de vida, tomando mais " << g.veneno << " de dano venenoso" << std::endl;
                }
                break;
            default:
            std::cout << "Voce tem que decidir o que fazer, ficar parado ai nao vai te fazer um heroi." << std::endl;
            }
    }while(g.vidaM != 0 && p.energia !=0);
        if(g.vidaM == 0){
            std::cout << "O inimigo morreu, vamos continura nossa jornada" << std::endl;
            p.creditos = p.creditos + g.dinheiro;
            p.forcaFisica = p.forcaFisica + 50;
            p.forcaMagica = p.forcaMagica + 50;
            mostraStatusDoJogador(p);
        }
        if(p.energia == 0){
            std::cout << "Voce morreu, sua jornada acabou" << std::endl;
        }
    std::cout << "Conseguimos nossa Pena da Fenix Glacial, proxima parada, Floresta de Nederviersel." << std::endl;
}


int main(int argc, char** argv){
    setlocale(LC_ALL,"");
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();
    struct InimigosGelidos g = faseFlorestaGelida();

    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);

    faseFlorestaGelida(j, g);

}