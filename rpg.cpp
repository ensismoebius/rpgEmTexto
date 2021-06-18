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
    std::getline(std:: cin, nome);

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
    std::cout <<"\n**************STATUS JOGADOR:******************\n"<< std::endl;
    std::cout << "Altura:" << p.altura/100.0 <<" metros\n"<<
                "Energia Vital:" << p.energia<< "\nForca de intensidade:" <<
                p.forcaFisica << "\nPoder Magico: " <<
                p.forcaMagica << "--Orbites\nMoedas:$" << p.creditos << std::endl;
    std::cout <<"\n***********************************************\n"<< std::endl;
}


struct inimigoFloresta 
{
   std::string nome;

    unsigned int energia;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
};

struct inimigoFloresta faseDaFloresta()
{
   struct inimigoFloresta f;

    f.energia=200;
    f.forcaFisica=50;
    f.forcaMagica=50;
    f.creditos=geraAleatorio() * 50;
    return f;
};

void mostraStatusDoInimigo(struct inimigoFloresta &f)
{ 
        if(f.energia == 0)
        {
            std::cout << "O inimigo morreu" << std::endl;
            return;   
        }
         std::cout << " Vida:" << f.energia<<"\n"
                "Forca Magica:" << f.forcaMagica<<"\n" << "Forca Fisica:" <<
                f.forcaFisica << std::endl;
        
}

void faseDaFloresta(struct Personagem &p, struct inimigoFloresta &f)
{
     unsigned int opcao = 0;

    std::cout <<"\n\n*********************************xxxxxxxxxxxFLORESTA_DE_NEDERVIERSELxxxxxxxxxx************************************\n"<< std::endl;
    std::cout<<"Após enfrentar Murilo de Gelo.Nosso heroi se aproxima cada vez mais do seu destino final em sua jornada\n" << std::endl;
    std::cout<<"contra o Rei Demonio. Agora que possui a pena da Fenix Glacial em suas maos conseguira matar o Lich que\n" << std::endl;
    std::cout<<"habita no lado sombrio da Floresta de Nederviersel. Nosso heroi se depara com uma bifurcação a sua\n," << std::endl;
    std::cout<<"frente e  observa que o caminho a sua direita eh repleto de arvores com aparencia\n" << std::endl;
    std::cout<<"decadente que emanam murmurios lamoriosos.Ja o caminho a sua esquerda é encoberto por uma nevoa\n" << std::endl;
    std::cout<<"espessa e desse local eh possivel ouvir clamores por socorro\n"<<std::endl;
    std::cout<<"ESCOLHA UM CAMINHO\n"<<std::endl;
    std::cout<<"\n1-Direita\n2-Esquerda"<<std::endl;
    std::cout <<"\n*********************************xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*********************************\n"<< std::endl;
    std::cin>>opcao;

     
     if(opcao==1)
        {std::cout <<"\n*********************************xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx************************************\n"<< std::endl;
         std::cout<<"Voce adentrou pela as arvores horripilantes e os murmurios cessaram instaneamente,\n o unico barulho audivel era apenas o de sua respiracao.\n"<<std::endl;
         std::cout<<"Uma sensaçao de panico se apossou dele bem como a certeza de que estava sendo observado"<<std::endl;
         std::cout<<"conforme caminhava.\nApos perambular sem rumo por horas ele nota uma figura concurda proximo a uma caverna\n"<<std::endl;
         std::cout<<"Conforme vai se aproximando a figura vem tormando forma de uma criatura horripilante"<<std::endl;
         std::cout<<"Seu cranio era totalmente exposto e de sua testa saiam dois cifres semelhantes ao de um cordeiro\n"<<std::endl;
         std::cout<<"e estava trajando um manto surrado\nNaquele momento ele teve consciencia que estava diante do temivel Lich"<<std::endl;
         std::cout<<"\n*********************************xxxxxx UMA BATALHA SE INICIA xxxxxxx**********************************\n"<<std::endl;
         std::cout <<"\n**************STATUS DO LICH:******************\n"<< std::endl;
         mostraStatusDoInimigo(f);
        

            do
            {std::cout <<"\n**************ESCOLHA A SUA ACAO******************\n"<< std::endl;
             std::cout <<"\n1-AtaqueFisico(custa 8 de energia vital)"<< std::endl;
             std::cout <<"\n2-Ataque Magico(custa 5 de energia vital)" << std::endl;
             std::cout <<"\n3-Defender(Sem custos de energia vital)" << std::endl;
             std::cout <<"\n**************xxxxxxxxxxxxxxxxxxx*****************\n"<< std::endl;
             std::cin >> opcao;

             switch(opcao)
               {
                  case 1:
                    if(f.energia < p.forcaFisica)
                    {
                     f.energia = 0;
                     
                    }else{
                     f.energia = f.energia - p.forcaFisica; 
                     p.energia=p.energia-8;
                        if(p.energia<8)
                        {
                         p.energia=0;
                         mostraStatusDoJogador(p);
                         return;
                        }
                     std::cout <<"**************STATUS_BATALHA******************"<< std::endl;
                     std::cout <<"Vida Linch:" <<f.energia<< "\nSua Vida atual é:"<< p.energia<< std::endl;
                     std::cout <<"**************xxxxxxxxxxxxxxxxxxx*************"<< std::endl;
                    }

                   
                    break;

                case 2:
                    if(f.energia < p.forcaFisica)
                    {
                     f.energia = 0;
                     mostraStatusDoInimigo(f);
                    }else{
                     f.energia = f.energia - p.forcaMagica; 
                     p.energia=p.energia-5;
                        if(p.energia<5)
                        {
                         p.energia=0;
                         mostraStatusDoJogador(p);
                         return;
                        }
                     std::cout <<"**************STATUS_BATALHA******************"<< std::endl;
                     std::cout <<"Vida Linch:" <<f.energia<< "\nSua Vida atual é:"<< p.energia<< std::endl;
                     std::cout <<"**************xxxxxxxxxxxxxxxxxxx*************"<< std::endl;
                    }
                    break;

                case 3:

                    if(p.energia < f.forcaFisica)
                    {
                    p.energia = 0;
                    mostraStatusDoJogador(p);
                    return;
                    
                    }else{
                     p.energia = p.energia - f.forcaFisica;
                     std::cout <<"Vida Atual Heroi:" <<p.energia << std::endl;
                    }
                    break;
                    default:
                    std::cout << "Opção Invalida" << std::endl;

                }  

            }while(f.energia != 0 && p.energia !=0);
            if(f.energia == 0){
            p.creditos = p.creditos + f.creditos;
            p.forcaFisica = p.forcaFisica + 50;
            p.forcaMagica=p.forcaMagica+250;
            std::cout <<"\n**************xxxxxxxxxxxxxxxxxxx******************\n"<< std::endl;
            std::cout<<"Após derrotar o Lich nosso heroi agora esta em posse de seu poderoso cajado"<<std::endl;
            std::cout<<"que o possibilatara ressuscitar o druida Stregga que o auxiliara na derrocada contra o Rei Demonio"<<std::endl;
            std::cout<<"Proxima parada masmorra"<<std::endl;
            std::cout <<"\n**************xxxxxxxxxxxxxxxxxxx******************\n"<< std::endl;
             mostraStatusDoJogador(p);}
             return;

        }
    if(opcao==2)
        {
        std::cout <<"\n****************************xxxxxxxxxxxxxxxxxxx******************************\n"<< std::endl;
        std::cout << "Voce foi consumido pela nevoa deixando sua visao completamente obstruida" << std::endl;
        std::cout << "O grito se eleva cada vez mais causando confusao mental em nosso heroi" << std::endl;
        std::cout << "Eis que surge de dentro da nevoa uma jovem mulher vestida com uma mortalha" << std::endl;
        std::cout << "Era a deusa da Morte\nNaquele momento ele teve consciencia de seu triste fim" << std::endl;
        p.energia = p.energia - p.energia;
        std::cout <<"\n****************************xxxxxxxxxxxxxxxxxxx******************************\n"<< std::endl;
        }
         
     
}

int main(int argc, char** argv)
{
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();
    struct inimigoFloresta f= faseDaFloresta();
    std::cout << "Você recebeu um presente das divindades da terra!\n";
    std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

    mostraStatusDoJogador(j);
    
    faseDaFloresta(j,f);
 
}
