#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

// TODO Fazer uma forma do jogador ou jogadora escolher sua raÃƒÆ’Ã‚Â§a
// TODO Sendo que cada raÃƒÆ’Ã‚Â§a tem a possibilidade de  ter mais ou menos atributos que as outras

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
    std::cout << "o rei DemÃƒÆ’Ã‚Â´nio dominou as principais forÃƒÆ’Ã‚Â§as de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanÃƒÆ’Ã‚Â§as decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e nÃƒÆ’Ã‚Â£o conseguimos nos defender\n";
    std::cout << "precisamos de alguÃƒÆ’Ã‚Â©m que nos lidere para a derrocada deste maldito!\n";
    std::cout << "VocÃƒÆ’Ã‚Âª ÃƒÆ’Ã‚Â© nossa escolha!! E... a propÃƒÆ’Ã‚Â³sito... qual ÃƒÆ’Ã‚Â© mesmo o seu nome?\n";

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
        std::cout << "VocÃƒÆ’Ã‚Âª morreu!!!" << std::endl;
        return;
    }

    std::cout << "VocÃƒÆ’Ã‚Âª agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma forÃƒÆ’Ã‚Â§a de intensidade " <<
                p.forcaFisica << " e um poder mÃƒÆ’Ã‚Â¡gico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaMasmorra(struct Personagem &p){
    
    unsigned int opcao = 0;
    
    
    std::cout << "Parabéns, após tanto suor e luta você chegou a masmorra," << std::endl;
    std::cout << "mas achando que a vida é um morango? Vai jovem pigmeu escolha um desses 3 caminhos." << std::endl;
    std::cout << "1-Esquerda\n2-Direita\n3-Meio"  << std::endl;
    std::cin >> opcao;
    
    
    if(opcao == 1){
        std::cout << "VocÃƒÂª estÃƒÂ¡ em um tunel e ele estÃƒÂ¡ ficando cada vez mais apertado," <<std::endl; 
        std::cout << "vocÃƒÂª precisa abrir uma porta para escapar, mas pra isso voÃƒÂ§ÃƒÂª precisa decifrar o enigma:"<< std::endl;
        
        
        
        do{
            
            
        std::cout << "Sempre quando chego trago a tristeza\nMas sempre chego na hora certa\n" << std::endl;
        std::cout <<  "As vezes venho depois de uma doenÃƒÂ§a\nE outras, depois de um ato de violÃƒÂªncia\n" << std::endl;
        
        std::cout <<"1-Vento\n2-Morte\n3-Arroz" << std::endl; 
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-50;
            
            std::cout << "Sua escolha nÃƒÂ£o foi das mais sabias, volte e tente novamente" << std::endl;
            
            if(p.energia<50){ p.energia=0;
                return;
            }
            break;
            
            case 2:
            std::cout << "Parabéns jovem pigmeu, você passou de fase" << std::endl;
            
            break;
            
            case 3:
            p.energia=p.energia-10;
            std::cout << "Sua escolha nÃƒÂ£o foi das mais sabias, volte e tente novamente" << std::endl;
            
            if(p.energia<10){ p.energia=0;
                return;
            }
            break;
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=2);
        
        opcao=0;
        
    do{
            
            
        std::cout << "VoÃƒÂ§ÃƒÂª entrou em um labirinto com 3 caminhos, escolha um caminho:" << std::endl;
        
        
        std::cout <<"1-Caminho escuro\n2-Caminho claro\n3-Caminho barulhento" << std::endl;
         
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-p.energia;
            std::cout << "VocÃƒÂª caiu em um poÃƒÂ§o de lava" << std::endl;
            return;
            
            case 2:
            std::cout << "Boa noiticia, você não está morto" << std::endl;
            break;
            
            case 3:
            p.energia=p.energia-10;
            std::cout << "3:Sua escolha nÃƒÂ£o foi das mais sabias, volte e tente novamente" << std::endl;
            if(p.energia<10)
            {
                p.energia=0;
                return;
            }
            break;
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=2);
          opcao=0;
          
        do{
            
            
        std::cout << "VocÃƒÂª estÃƒÂ¡ em uma sala com trÃƒÂªs alavancas, acione elas na ordem correta para abrir a porta\n" << std::endl;
        
        std::cout <<  "1-dica: NÃƒÂ£o sou a ultima, e nem a primeira." << std::endl;
        std::cout<<   "2-dica: A contagem comeÃƒÂ§a por mim" << std::endl;
        std::cout<<   "3-dica: Sou maior que 1 e menor que 4" << std::endl;
    
        
        std::cout <<"1: 1,3,2\n" << std::endl;
        std::cout << "2: 3,1,2\n" << std::endl;
        std::cout << "3: 2,1,3" << std::endl; 
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-8;
             if(p.energia<8)
             { 
                 p.energia=0;
                return;
             }
            break;
            
            case 2:
            p.energia=p.energia-10;
             if(p.energia<10){ p.energia=0;
                return;
             }
            break;
            
            case 3:
            std::cout << "Olha olha, você está me surpreendendo" << std::endl;
            break;
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=3);
         return;
    }
        
        
        
      if(opcao == 2){
        std::cout << "VocÃª estÃ¡ em um tunel subaquÃ¡tico e precisa nadar para sobreviver" <<std::endl; 
        
        
        
        do{
            
            
        std::cout << "Escolha uma direÃ§Ã£o, esquerda ou direita" << std::endl;
        
        
        std::cout <<"1-Esquerda\n2-Direita" << std::endl; 
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-25;
            std::cout << "VocÃª encontrou uma criatura aquÃ¡tica mitolÃ³gica" << std::endl;
            
            if(p.energia<25)
            { 
                p.energia=0;
                return;
            }
            break;
            
            
            case 2:
           
            std::cout << "ApÃ³s nadar muito vocÃª consegue sair com vida, agora siga a sua jornada" << std::endl;
            
                 
            break;
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
        }
               
        }
    
         while(opcao!=2);
    
        
        opcao=0;
        
    do{
            
            
        std::cout << "VocÃª acabou sendo envenenado durante a sua ultima jornada, mas tenho uma boa noiticia,\n" << std::endl;
        std::cout << "Na sua frente tem dois potes, porÃ©m sÃ³ um deles Ã© o antidoto pra o veneno.Escolha um pote:" << std::endl;
        
        
        std::cout <<"1- O grande\n2- O pequeno" << std::endl;
         
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-p.energia;
            std::cout << "Ops pote errado, Ã© apenas Ã¡gua, vocÃª nÃ£o resistiu" << std::endl;
            return;
            
            case 2:
            std::cout << "Boa escolha pequeno gafanhoto, o veneno nÃ£o estÃ¡ mais em seu corpo,\n" << std::endl;
            std::cout << "agora vocÃª pode seguir seu caminho" << std::endl;
            break;
            
            
            
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=2);
          opcao=0;
          
        do{
            
            
        std::cout << "VocÃª encontrou uma bruxa que estÃ¡ disposta a te ajudar com a sua jornada,\n" << std::endl;
        std::cout << "Deseja aceitar a sua ajuda?\n" << std::endl;
        
        std::cout <<  "1-Sim" << std::endl;
        std::cout <<   "2-NÃ£o" << std::endl;
       
        std::cin >> opcao;
    
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-p.energia;
            std::cout << "VocÃª nÃ£o deu ouvidos a sua mÃ£e quando ela disse que bruxas nÃ£o sÃ£o confiavÃ©s,\n" << std::endl;
            std::cout << "Agora ela te jogou em feitiÃ§o" << std::endl;
             return;
            
            case 2:
           p.energia=p.energia-p.energia;
           std::cout << "VocÃª resolveu lembrar de sua mÃ£e e nÃ£o deu ouvidos a bruxa, porÃ©m era tarde de mais,\n" << std::endl;
           std::cout << "VocÃª estÃ¡ preso em uma areia movediÃ§a" << std::endl;
           return;
            
           
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=4);
        
          return;
    }
    
    if(opcao == 3){
        std::cout << "VocÃª estÃ¡ em um salÃ£o escuro com dois caminhos, escolha um deles:" <<std::endl; 
        
        
        
        do{
            
            
        std::cout << "Escolha um caminho, esquerda ou direita" << std::endl;
        
        
        std::cout <<"1-Esquerda\n2-Direita" << std::endl; 
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            
            std::cout << "Otima escolha, esse caminho parece ser seguro" << std::endl;
            break;
            
            
            case 2:
            std::cout << "NÃ£o foi uma boa escolha, espinhos afiados sairam da parede e fizeram de vocÃª uma penera" << std::endl;
            p.energia=p.energia-p.energia;
            return;
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
        }
               
        }
    
         while(opcao!=1);
    }
        
        opcao=0;
        
    do{
            
            
        std::cout << "Você está em frente a uma porta, mas derepente começa subir uma fumaça tóxica,\n" << std::endl; 
        std::cout << "Você precisa escolher entre voltar, ou tentar achar uma saida" << std::endl;
        
        
        std::cout <<"1- Voltar:\n2- Achar outra saida" << std::endl;
         
        std::cin >> opcao;
        
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-p.energia;
            std::cout << "Não foi uma boa escolha, o caminho estava fechado" << std::endl;
            return;
            
            case 2:
            std::cout << "Você foi corajoso e achou uma pequena fresta na parede e conseguiu escapar" << std::endl;
            break;
            
            
            
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=2);
          opcao=0;
          
        do{
            
            
        std::cout << "Você acaba encuralado por um esqueleto com uma espada encantada e precisa batalhar com ele,\n" << std::endl;
        std::cout << "Escolha sua arma:" << std::endl;
        
        
        std::cout <<  "1-Graveto" << std::endl;
        std::cout <<   "2-Espada" << std::endl;
       
        std::cin >> opcao;
    
        
        switch(opcao){
            
        
            case 1:
            p.energia=p.energia-p.energia;
            std::cout << "É serio que você fez essa escolha jovem gafanhoto? Nem preciso falar que você morreu néh" << std::endl;
            
             return;
            
            case 2:
           p.energia=p.energia-p.energia;
           std::cout << "Boa escolha, porém após tantos obstáculos você está muito fraco para batalhar e" << std::endl; 
           
           return;
            
           
            
            default:
            std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
               
                  }
    
        } while(opcao!=3);
        std::cout << "NarraÃ§Ã£o blabla" << std::endl;
        p.energia=p.energia-p.energia;
         return;
    }

    
int main(int argc, char** argv)
{
    // s = seed rand = aleatÃƒÆ’Ã‚Â³rio                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();

    std::cout << "VocÃƒÆ’Ã‚Âª recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);

    faseDaMasmorra(j);

    mostraStatusDoJogador(j);
}
