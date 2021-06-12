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
        std::cout << "press f to pay respect" << std::endl;
        return;
    }

 

    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma força de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

 

void faseDaVeinha(struct Personagem &p){
    
    unsigned int opcao=0;

 

       while(opcao < 1 || opcao > 3){
        std::cout << "ao iniciar sua jornada, saindo de seu vilareijo calmo e pacífico," << std::endl;
        std::cout << "essa é a realidade da grande maioria dos 'herois\n'" << std::endl;
        std::cout << "após se distanciar relativamente de sua terra natal, você encontra um grupo de jovens, cuja aparência se assemelha aos seguidores do rei Demônio\n" << std::endl;
        std::cout << "eles estão espancando uma senhora de aparência duvidosa\n você possui três opções: 1-procurar por ajuda\n 2-ignorar e seguir sua jornada\n 3-mesmo estando em desvantagem e possuir poucas forças, tentar salvar aquela senhora!" << std::endl;
        std::cin >> opcao;
    }

 

    if(opcao == 1){
        
        opcao=0;
        
        std::cout << "uma pequena e humilde vila está ao seu alcance, você corre para lá em procura de um guarda" << std::endl;
        
        std::cout << "ao encontrar um guarda, você explica a ocasião e pede por ajuda " << std::endl;
        std::cout << "ambos saem correndo em direção á idosa e se deparam com uma espantosa cena!!!" << std::endl;
        std::cout << "a idosa que estava sendo espancada, misteriosamente aparece sobre os corpos de todos os seus agressores(aparentemente inconscientes) " << std::endl;
        std::cout << "ao questionar a idosa, ela misteriosamente some e deixa um pacote no chão " << std::endl;
        std::cout << "1-abrir  2-guardar em sua mochila" << std::endl;
        std::cin >> opcao;
        
        if(opcao == 1){
            std::cout << "ao abri-la, você se depara com um misterioso item que te altera de alguma maneira" << std::endl;
            p.energia = p.energia*1.15;
            std::cout <<"você obteve um aumento em sua energia máxima! " << p.energia << std::endl;
        }
        }

 

       if(opcao == 2){

 

          std::cout << "é uma escolha egoísta, porém, segura, sua aventura continua!!!" << std::endl;  

 

       }

 

    if(opcao == 3){
        
        opcao = 0; 
         while(opcao < 1 || opcao > 2){
        std::cout << "após muito apanhar, sua vitória é certa, os agressores recuam e deixam a idosa em paz" << std::endl;
        std::cout << "IDOSA:muito obrigada por sua coragem, jovem, sei que é algo egoísta de minha parte, mas...\n poderia me ajudar a carregar meus pertences até minha moradia? " << std::endl;  
        std::cout << "1-ajuda\n  2-inventa alguma desculpa" << std::endl;
        std::cin >> opcao;
        p.energia = p.energia*0.20;
         }
         
         if (opcao == 1){
             std::cout << "a viagem é longa e cansativa, sua vitória não foi barata, consequentemente sua energia está escassa\n" << std::endl;
             std::cout << "seu sangramento cessa vagarosamente, voce está só o pó!\n " << p.energia << "de vida restante" << std::endl;
             std::cout << "quando chega na 'casa' da senhora, percebe que na verdade é uma pequena cabana no meio de uma floresta\n" << std::endl;
             std::cout << "ao adentrar seus aposentos, a velha senhore lhe cura com estranhos liquidos(aparentemente algo comestivel)\n" << std::endl;
             std::cout << "seu corpo se cura rapidamente e sente-se com novos poderes\n" << std::endl;
             p.energia = p.energia*5;
             std::cout << "a idosa se apresenta, seu nome é Lucy.\n" << std::endl;
             std::cout << "contando sua história, ela diz que seu filho era um bravo guerreiro que morrera lutando bravamente contra o rei demônio\n" << std::endl;
             std::cout << "como recompensa por sua coragem, você recebe o antigo equipamento de seu falecido filho, assim, podendo lutar, equilibradamente contra inimigos poderosos" << std::endl;
             p.energia=p.energia*1.8;
             p.forcaFisica=p.forcaFisica*2.5;
             p.forcaMagica=p.forcaMagica*0.6;
             std::cout << "com a armadura e espada de um bravo guerreiro seus atributos sobem: " << std::endl;
             std::cout << "sua nova força física é " << p.forcaFisica << std::endl;
             std::cout << "com potentes defesas, sua vida máxima é elevada " << p.energia <<  std::endl;
             
         }
         if(opcao== 2){
             std::cout << "após a luta, sua sobrevivência é duvidosa.\n" << std::endl;
             std::cout << "como forma de agradecimento, a senhora retira uma estranha esfera de sua bolsa e diz que será ultil de alguma forma\n" << std::endl;
             std::cout << "sua vida é curada completamente e você recebe equipamentos básicos de um mago, subindo assim, seus atributos\n" << std::endl;
             std::cout << "IDOSA: meu filho foi um bravo guerreiro outrora, infelizmente nao habita entre nós, creio que habilidades de um mago, com ataques a longa distância, seja algo que te ajudará a sobreviver!" << std::endl;
             std::cout << "sua força mágica aumenta: " << p.forcaMagica << std::endl;
             
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

 

    faseDaVeinha(j);

 

    mostraStatusDoJogador(j);
}