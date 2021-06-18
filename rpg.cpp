#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>

// 1/3 Estrutura do Personagem
struct Personagem{
    std::string nome;

    unsigned int vida;
    unsigned int energia;
    unsigned int altura;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int creditos;
    unsigned int habilidadesMagicas;
};
// 1/3Fim 
float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

// 2/3Estrutura do Personagem
struct Personagem boasVindasDoJogo(){
    std::cout << "Boas vindas ao nosso mundo!\n";
    std::cout << "Um sentimento de obscuridade tomou conta de nossa terra, \n";
    std::cout << "o rei Demonio dominou as principais forcas de defesa do nosso povo\n";
    std::cout << "e a cada dia que passa as esperanças decaem mais e mais...\n";

    std::cout << "Como somos um bando de incompetentes e nC£o conseguimos nos defender\n";
    std::cout << "precisamos de alguem que nos lidere para a derrocada deste maldito!\n";
    std::cout << "Voce e nossa escolha!! E... a proposito... qual e mesmo o seu nome?\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sir " << nome << "!\n";
// 2/3 Fim

// 3/3 Estrtura do Personagem
    struct Personagem eu;

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;
    eu.habilidadesMagicas=21;
    eu.vida=100;

    return eu;
};
// 3/3 Fim 

// 1/2 Estrutura Inimigo
    struct Inimigo{
 	std::string nome;
 	unsigned int vida;
    unsigned int forcaFisica;
    unsigned int forcaMagica;
    unsigned int habilidadesMagicas;
    unsigned int Gdano;
    unsigned int Pdano;
};
// 1/2Fim 

// 2/2 Estrutura Inimigo
    struct Inimigo faseDaMontanha(){
	
    struct Inimigo i;
    
    i.forcaMagica=100;
    i.forcaFisica= geraAleatorio() * 120;
    i.habilidadesMagicas=100;
    i.vida=150;
    i.Gdano= (geraAleatorio()*99)+2;
    i.Pdano= geraAleatorio()*40;
    
    return i;
    
};
 // 2/2Fim    


void mostraStatusDoJogador(struct Personagem &p){

    if(p.energia == 0){
        std::cout << "Voce morreu!!!" << std::endl;
        return;
    };
    if(p.vida == 0)
    {
        std::cout << "Você morreu!!!" << std::endl;
        return;
    };

    std::cout <<"\n**************STATUS JOGADOR:******************\n"<< std::endl;
    std::cout << "Altura:" << p.altura/100.0 <<" metros\n"<<
                "Energia Vital:" << p.energia<< "\nForca de intensidade:" <<
                p.forcaFisica << "\nPoder Magico: " << p.forcaMagica << "--Orbites\nMoedas:$" << p.creditos<<"\nHabilidade Magica:"<<p.habilidadesMagicas<<"\nVida:"<<p.vida << std::endl;
    std::cout <<"\n***********************************************\n"<< std::endl;
                
}


void faseDaMontanha(struct Personagem &p, struct Inimigo &i)
{
    
    
    unsigned int opcao = 0;
    

    while(opcao < 1 || opcao > 2){
        
        std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
        std::cout << "**Narrador-- Agora que já nos equipamos, suportaremos os perigos contidos nas montanhas congeladas.\n" << std::endl;
        std::cout << "Cuja a lenda menciona a existência de um mago que habita o local. Se esta estiver correta\n" << std::endl;
        std::cout << "conseguiremos usufruir de sua sabedoria mistica que sera util em nossa jornada.\n"<<std::endl;
        std::cout << " **Narrador--'Durante a escalada o heroi é atingido por uma nevasca.Com o objetivo\n" << std::endl; 
        std::cout << " de se proteger decide se abrigar numa caverna, mal sabe ele dos segredos que o aguardam lá dentro.\n" << std::endl;
        std::cout << "Então cuidadosamente se esgueira pela pequena abertura.Para sua surpresa deparou-se\n"<<std::endl;
        std::cout << " com um ancião dormindo sob um altar." << std::endl;
        std::cout << " O que devo fazer?\n" <<std::endl;
        std::cout << "1-Ataca-lo enquanto dorme.\n2-Acorda-lo pacificamente." << std::endl;
        std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
        std::cout << "\n" << std::endl;
        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "\n**Heroi-- Empunho a minha arma e decido desferir um golpe em seu peito,\n" << std::endl;
        std::cout << "porem a lamina encosta de relance.Inesperadamente sou lancado contra uma parede\n" << std::endl; 
        std::cout << "para o meu desespero o mago despertou antes que conseguisse mata-lo.\n" << std::endl;
        std::cout << "Me dou conta que uma jaula surge ao meu redor me prendendo.\n" << std::endl;
        std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
        p.vida=p.vida-i.Pdano;
        if(p.vida<i.Pdano){
            p.vida=0;
            return;
        }
        
        std::cout << "\n**Narrador-- O impacto lhe causou dano, voce possui: " << p.vida << " de vida atual\n" << std::endl;
        std::cout << "Escuto uma voz fria como gelo me indagando--'Como me encontrou??'\n"<< std::endl;
        std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
        std::cout<<  "Oque devo responder?\n"<<std::endl;
        std::cout<<  "1-**Heroi-- Não te interessa.\n"<<std::endl;
        std::cout<<  "2-**Heroi-- Vim em busca de um abrigo para achar voce apos a nevasca, mas agora que ja estou aqui, vim mata-lo atras do artefato mistico, que me protejerá do frio da floresta gélida.\n"<<std::endl;
        std::cout<<  "3-**Heroi-- Vim em busca de um abrigo para achar voce apos a nevasca," << std::endl;
        std::cout << "mas agora que ja estou aqui, vim atras de você perdedor, que está se escondendo do Rei Dêmonio.\n "<< std::endl;
        std::cin >> opcao;
        
            switch(opcao)
            {
               case 1:
               std::cout << "\nTolo agora voce esta fadado a passar a resto da vida nessa jaula\n" << std::endl;
               std::cout << "MUAHAHAHAHA\n" << std::endl;
               return;

               case 2:
               std::cout << "Mas então você jovem guerreiro deveria ter ao menos pedido para mim, pois tem um garoto\n" << std::endl; 
               std::cout << "no qual estou esperando cujo foi escolhido para nos salvar do Rei Demônio e a proposito qual seria seu nome?Então o heroi responde: Eu sou o escolhido.\n"<< std::endl;
               std::cout << "Aaaaa então você é o escolhido, ao invés de ter me atacado deveria ter conversado comigo,\n" << std::endl;
               
               
               break;
               case 3: 
               std::cout<< " Mago-- Perdedor? O Rei Dêmonio ele tem uma unica fraqueza,\n" << std::endl; 
               std::cout << "que seria se o tão falado escolhido o enfrentasse, mas aproposito qual seria seu nome?\n" << std::endl; 
               std::cout << "Heroi-- Eu sou o escolhido e vim atras do artefato mistico.\n" << std::endl;
               
               break;

               default: 
               std::cout<<"Opcao Invalida"<<std::endl;
            }
        
    }


    if (opcao == 2)
    {
        
              std::cout << "\nHeroi-- Entao balanco seus ombros suavemente tomando cuidado para não assusta-lo\n" << std::endl;
              std::cout << "Sou atingido por um raio na regiao do peito que veio das mãos do ancião" << std::endl;
              p.vida=p.vida-i.Gdano;
              std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
        
        if(p.vida <= 30)
        {
            std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
            std::cout << "\nSua vida atual é: " << p.vida << "\n" << std::endl; 
            std::cout << "O dano sofrido te enfraqueceu.\n" << std::endl;
            std::cout << "então oque deseja fazer??\n1-Contra atacar. \n2-Não fazer nada. " << std::endl;
            std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
            std :: cin >> opcao;
        }
        if(p.vida > 30)
        {
            std::cout << "Narrador-- Nossa que sorte foi que a magia que ele usou não pegou em cheio\n" << std::endl; 
            std::cout << "Voce está com " << p.vida << " de vida.\n" << std::endl; 
            std::cout << "Agora o que deseja fazer?" << std::endl;
            std::cout << "\n1-Contra atacar. \n2-Não fazer nada."  << std::endl;
                       std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
            std :: cin >> opcao;
        }
        
                switch(opcao){
                
                    case 1:
                    
                    i.vida=i.vida - p.forcaFisica;  
                    
                    if(i.vida > 50)
                    {
                        std::cout << "\n**Narrador-- Vida atual do inimigo: " << i.vida << "\n" <<  std::endl;
                        std::cout << "Voce causou pouco dano e deixou sua defesa vulneravel:\n" << std::endl;
                        p.vida = p.vida - p.vida;
                    }
                    if(i.vida <= 50)
                    {
                         std::cout << "\n**Narrador-- Vida atual do inimigo: " << i.vida << "\n" <<  std::endl;
                        std::cout << "Voce causou bastante dano, mas deixou sua defesa vulneravel:\n" << std::endl;
                        p.vida = p.vida - p.vida;
                    }
                    
                    return;
                    
                    case 2:
                    
                    std::cout << "\n**Narrador-- Então o mago aparece ao seu lado e lhe diz: Oque faz aqui jovem guerreiro ?\n" << std::endl;
                    std::cout << "**Herói-- responde a ele: vim em busca do artefato mistico para que ele possa atravessar as florestas gélidas.\n" << std::endl;
                    break;
                    
                    
                    default: 
                    
                    return;
                }
    }
              std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
              std::cout << "\n**Mago-- Então para que você prove que é o escolhido me responda a seguinte pergunta:\n" << std::endl;
              std::cout << "O que o livro faz?\n" << std::endl;
              std::cout << "1-Eu sei.\n2-Não faço ideia.\n" << std::endl;
              std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
              std::cin >> opcao;
        
            if(opcao == 1)
            {
                std::cout << "Heroi--O livro me ajudara a passar pelas florestas gélidas e\n" << std::endl;
                std::cout << "que com ele conseguirei unir todos os itens miticos para derrotar o Rei Demonio.\n" << std::endl;
                std::cout << "Mago-- Impostor o verdadeiro guerreiro não saberia que com ele voce podera unir os itens miticos." << std::endl;
                
            }
            
            if(opcao == 2)
            {
              std::cout << "**Heroi-- Eu não mas a unica coisa que me falaram foi que eu precisaria dele para que eu passe pelas Florestas Gélidas." << std::endl;
              std::cout << "\n**Narrador-- Então ele percebendo que você é o salvador, pede perdão a voce pelos danos causados e que se voce sair desse " << std::endl;
              std::cout << "jeito ira morrer lá fora então ele te dá uma sopa na qual ele diz que ela ira te curar em +40 de vida e também ira melhorar um pouco suas habilidades magicas em +15." << std::endl;
                
                std::cout << "Voce estava com " << p.vida << " de vida\n" << std::endl; 
                std::cout << "e com " << p.vida << " de habilidades Magicas.\n" << std::endl; 
                p.vida=p.vida+40;
                p.habilidadesMagicas=p.habilidadesMagicas+15;
            
                std::cout << "Agora voce está com " << p.vida << " de vida.\n" << std::endl; 
                std::cout << "e com " << p.habilidadesMagicas << " de habilidades Magicas.\n" << std::endl; 
            } 
              
        
        
              std::cout << "\n**Narrador-- Ele te explica, que o livro te ajudará a passar pelas Florestas Gélidas,\n" << std::endl;
              std::cout << "pois quem transporta o livro ira usufruir de uma magia onde te protejerá de frios extremos.\n" << std::endl;
              
              std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
              
              std::cout << "\n**Heroi-- Agora irei seguir minha missão de passar pelas florestas gélidas.\n" << std::endl;
              std::cout << "\n**Narrador-- Então o heroi se despede do mago sai da caverna em meio a nevasca e segue sua missão.\n" << std::endl;
              std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
}
    int main(int argc, char** argv)
    {
    // s = seed rand = aleatório                                                
    // std::time vem da biblioteca ctime  
    std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

    struct Personagem j = boasVindasDoJogo();
    
    struct Inimigo i = faseDaMontanha(); 
    
    mostraStatusDoJogador(j);

    faseDaMontanha(j,i);

    mostraStatusDoJogador(j);
}
