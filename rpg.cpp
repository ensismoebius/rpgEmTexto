#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>

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
//Fase Labirinto

std::vector<std::string> RemoverOpcao(char opcao, std::vector<std::string> direcao) {
    std::vector<std::string> direcao2;
    for (int i = 0; i < direcao.size(); i++) {
        if (opcao != direcao[i][0]) {
            direcao2.push_back(direcao[i]);
        }
    }
    return direcao2;
}

char PerguntarDirecao(std::vector<std::string> direcao) {
    
    unsigned char opcao;
    std::cout << "Você pode escolher essas direções\n";
    for (int i = 0; i < direcao.size(); i++) {
        std::cout << direcao[i][0] << " - " << direcao[i] + "\n";
    }
    std::cout << "Qual direção você escolhe?\n";
    std::cin >> opcao;
    system("clear||cls");
    return opcao;
}

//Seleciona Direcao
bool escolherDirecao(bool direcaoCorreta, std::list<char> mapa) {

    if (mapa.front() == 'X') {
        return true;
    }
    else {
        std::vector<std::string> direcao;
       

        direcao.push_back("Frente");
        direcao.push_back("Direita");
        direcao.push_back("Esquerda");
        
       
        bool ok=false;
        bool dC = false;

        do
        {
            if (direcaoCorreta) {
                do
                {
                    switch (PerguntarDirecao(direcao))
                    {
                    case'f':case'F':
                        direcao = RemoverOpcao('F', direcao);
                        std::cout << "\nVocê decidiu seguir em frente! \n\n";
                        if (mapa.front() == 'F') {
                            mapa.pop_front();
                           
                            dC = true;
                        }
                        break;
                    case'd':case'D':
                        direcao = RemoverOpcao('D', direcao);
                        std::cout << "\nVocê decidiu virar a direita! \n\n";
                        if (mapa.front() == 'D') {
                            mapa.pop_front();
                            
                            dC = true;
                        }
                        break;
                    case'e':case'E':
                        direcao = RemoverOpcao('E', direcao);
                        std::cout << "\nVocê decidiu virar a esquerda! \n\n";
                        if (mapa.front() == 'E') {
                            mapa.pop_front();
                            
                            dC = true;
                        }
                        break;
                    default:
                        std::cout << "Direcao não encontrada\n";
                        ok = true;
                        break;
                    }
                } while (ok);
                if (escolherDirecao(dC, mapa)) {
                    return true;
                }
                
            }
            else {
                do
                {
                    switch (PerguntarDirecao(direcao))
                    {
                    case'f':case'F':
                        direcao = RemoverOpcao('F', direcao);
                        std::cout << "\nVocê decidiu seguir em frente! \n\n";
                        if (mapa.front() == 'F') {
                            mapa.pop_front();
                        }
                        break;
                    case'd':case'D':
                        direcao = RemoverOpcao('D', direcao);
                        std::cout << "\nVocê decidiu virar a direita! \n\n";
                        if (mapa.front() == 'D') {
                            mapa.pop_front();
                        }
                        break;
                    case'e':case'E':
                        direcao = RemoverOpcao('E', direcao);
                        std::cout << "\nVocê decidiu virar a esquerda! \n\n";
                        if (mapa.front() == 'E') {
                            mapa.pop_front();
                        }
                        break;
                    default:
                        std::cout << "Direcao não encontrada\n";
                        ok = true;
                        break;
                    }
                } while (ok);;
                int op = geraAleatorio() * 5;
                
                switch (op)
                {
                case 1:  std::cout << "Você encontrou o fim desse caminho!\n"; break;
                case 2:  std::cout << "Não tem nada aqui!\n\n"; break;
                case 3:  std::cout << "Vozes desconhecidas...\n-Esse não é o seu caminho, volte antes que seja tarde demais!\n\n"; break;
                case 4:  std::cout << "Caminho sem saída!\n\n"; break;
                case 5:  std::cout << "Você andou... e andou... e percebeu que estava andando em círculo...\n\n"; break;
                default:
                    std::cout << "Você encontrou o fim desse caminho!\n\n";
                    break;
                }
                
                if (direcao.size() == 0) {
                    std::cout << "\nVocê percebeu que olhou todos os caminhos desse lado, então decidiu que deveria voltar e ir por um caminho diferente! \n\n";
                    return false;
                }
                else {
                    std::cout << "\nVocê voltou para o último ponto, antes de se perder, escolha outro caminho!!!\n\n";
                }
            }
            if (mapa.front() == 'X'){
                break;
            }
        } while (true);
        
    }
   

}

//Iniciar
void faseLabirinto(struct Personagem& p) {
    std::list<char> mapa;

    mapa.push_back('F');
    mapa.push_back('F');
    mapa.push_back('D');
    mapa.push_back('E');
    mapa.push_back('X');

    std::cout << "\n\nVocê chegou no labirinto do dragão, aqui vivia o dragão rei, já faz mais de um século que ele morreu, mas até hoje a boatos de quem passa por aqui que o seu coração ainda pulsa, e quem estiver no domínio do coração se tornara o mago mais poderoso de todos, talvez mais poderoso que o próprio Merlin. \n\nPressione qualquer tecla pra continuar...";
    getchar();
    system("clear||cls");
    std::cout << "Você entrou no labirinto...  \n\n";
    if (escolherDirecao(true, mapa)) {
        std::cout << "Você finalmente encontrou o coração do dragão! \n";
        p.forcaMagica = 60;
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

    //faseDaCidade(j);
    faseLabirinto(j);

    mostraStatusDoJogador(j);
}
