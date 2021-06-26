#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final.
 */

struct inimigoFloresta
{
		std::string nome;

		unsigned int energia;
		unsigned int forcaFisica;
		unsigned int forcaMagica;
		unsigned int creditos;
};

struct InimigosGelidos
{
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

struct Personagem
{
		std::string nome;
		std::string armamento;
		unsigned int energia;
		unsigned int altura;
		unsigned int forcaFisica;
		unsigned int forcaMagica;
		unsigned int creditos;
};

float geraAleatorio()
{
	return rand() / (float) RAND_MAX;
}

void mostraStatusDoInimigo(struct inimigoFloresta &f)
{
	if (f.energia == 0)
	{
		std::cout << "O inimigo morreu" << std::endl;
		return;
	}
	std::cout << " Vida:" << f.energia << "\n"
			"Forca Magica:" << f.forcaMagica << "\n" << "Forca Fisica:" << f.forcaFisica << std::endl;

}

struct InimigosGelidos faseFlorestaGelida()
{

	struct InimigosGelidos g;
	g.danoFofo = (geraAleatorio() * 20) + 1000;
	g.dano = geraAleatorio() * 80;
	g.dinheiro = geraAleatorio() * 50;
	g.vidaFofo = (geraAleatorio() * 50) + 1000;
	g.vidaP = (geraAleatorio() * 90) + 10;
	g.danoM = geraAleatorio() * 50;
	g.vidaM = (geraAleatorio() * 90) + 200;
	g.veneno = 7;
	return g;
}

struct Personagem boasVindasDoJogo()
{
	std::cout << "Bem vindo ao Hyako Secret Room!\n";
	std::cout << "Voce esta em um mundo onde a ficção é a realidade, \n";
	std::cout << "Com isso o mundo esta sobre ameaça de um ser poderoso chamado Leno Brega\n";
	std::cout << "ele busca migrar o reino de hyako para sua coleção de planetas no sistema solar de bueno...\n";

	std::cout << "nós de hyako secret room somos seres poderosos,porem ainda não podemos contra Leno brega\n";
	std::cout << "Por isso te convocamos aqui neste mundo,sabemos que voce podera nos ajudar...\n";
	std::cout << "Voce é a nossa unica salvação,nos diga quem é voce.\n";

	std::string nome;
	std::cin.ignore();
	std::getline(std::cin, nome);

	std::cout << "De agora em diante lhe chamaremos de Sr." << nome << "!\n";

	struct Personagem eu;

	eu.nome = nome;
	eu.energia = (geraAleatorio() * 90) + 10;
	eu.altura = geraAleatorio() * 300;
	eu.forcaFisica = geraAleatorio() * 100;
	eu.forcaMagica = geraAleatorio() * 50;
	eu.creditos = 26;

	return eu;
}

void mostraStatusDoJogador(struct Personagem &p)
{

	if (p.energia == 0)
	{
		std::cout << "press f to pay respect" << std::endl;
		return;
	}

	std::cout << "Você agora tem " << p.altura / 100.0 << " metros de altura, " << p.energia << " de energia com uma força de intensidade " << p.forcaFisica << " e um poder mágico de " << p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaCidade(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "voce está no quarto principal do reino, neste quarto voce ve duas portas: Uma porta te levara até a tenda e a outra porta te levara até uma loja de equipamentos.\n Que porta voce escolhera?" << std::endl;
		std::cout << "1-Tenda\n2-Loja de equipamentos" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;

		std::cout << "1-Nada\n2-Comida\n3-esferas do dragão" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Bife Acebolado (Dá muita energia)\n2-Banana Frita (Dá pouca energia)" << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 50)
					{
						p.energia += 50;
						p.creditos -= 50;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Esqueci,elas não estão a venda!!!" << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "mas que sujeito estranho....";
		}

	}

	if (opcao == 2)
	{
		std::cout << "O vendedor te pergunta: Pronto pra Descer o sarrafo em geral?" << std::endl;

		std::cout << "1-Não rapai\n2-kamado nichirin\n3-Death Note" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			std::cout << "Você tem bons olhos,porem não tem figuras suficientes inbecil" << std::endl;

			if (p.creditos >= 200)
			{
				std::cout << "Muitos Onis cairão por essa Katana!!" << std::endl;
				p.creditos = p.creditos - 200;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Você não merece esta Katana,domine sua respiração primeiro!!" << std::endl;
			}

		} else if (opcao == 3)
		{
			std::cout << "Quem diria,agora vou mostrar o novo mundo para Leno Brega!" << std::endl;

			if (p.creditos >= 25)
			{
				std::cout << "Muito bem..." << std::endl;
				p.creditos = p.creditos - 25;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Vaza daqui Fracote!!!" << std::endl;
			}
		} else
		{
			std::cout << "MORRA!." << std::endl;
		}
	}
}

void faseDaVeinha(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 3)
	{
		std::cout << "ao iniciar sua jornada, saindo de seu vilareijo calmo e pacífico," << std::endl;
		std::cout << "essa é a realidade da grande maioria dos 'herois\n'" << std::endl;
		std::cout << "após se distanciar relativamente de sua terra natal, você encontra um grupo de jovens, cuja aparência se assemelha aos seguidores do rei Demônio\n" << std::endl;
		std::cout << "eles estão espancando uma senhora de aparência duvidosa\n você possui três opções: 1-procurar por ajuda\n 2-ignorar e seguir sua jornada\n 3-mesmo estando em desvantagem e possuir poucas forças, tentar salvar aquela senhora!" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{

		opcao = 0;

		std::cout << "uma pequena e humilde vila está ao seu alcance, você corre para lá em procura de um guarda" << std::endl;

		std::cout << "ao encontrar um guarda, você explica a ocasião e pede por ajuda " << std::endl;
		std::cout << "ambos saem correndo em direção á idosa e se deparam com uma espantosa cena!!!" << std::endl;
		std::cout << "a idosa que estava sendo espancada, misteriosamente aparece sobre os corpos de todos os seus agressores(aparentemente inconscientes) " << std::endl;
		std::cout << "ao questionar a idosa, ela misteriosamente some e deixa um pacote no chão " << std::endl;
		std::cout << "1-abrir  2-guardar em sua mochila" << std::endl;
		std::cin >> opcao;

		if (opcao == 1)
		{
			std::cout << "ao abri-la, você se depara com um misterioso item que te altera de alguma maneira" << std::endl;
			p.energia = p.energia * 1.15;
			std::cout << "você obteve um aumento em sua energia máxima! " << p.energia << std::endl;
		}
	}

	if (opcao == 2)
	{

		std::cout << "é uma escolha egoísta, porém, segura, sua aventura continua!!!" << std::endl;

	}

	if (opcao == 3)
	{

		opcao = 0;
		while (opcao < 1 || opcao > 2)
		{
			std::cout << "após muito apanhar, sua vitória é certa, os agressores recuam e deixam a idosa em paz" << std::endl;
			std::cout << "IDOSA:muito obrigada por sua coragem, jovem, sei que é algo egoísta de minha parte, mas...\n poderia me ajudar a carregar meus pertences até minha moradia? " << std::endl;
			std::cout << "1-ajuda\n  2-inventa alguma desculpa" << std::endl;
			std::cin >> opcao;
			p.energia = p.energia * 0.20;
		}

		if (opcao == 1)
		{
			std::cout << "a viagem é longa e cansativa, sua vitória não foi barata, consequentemente sua energia está escassa\n" << std::endl;
			std::cout << "seu sangramento cessa vagarosamente, voce está só o pó!\n " << p.energia << "de vida restante" << std::endl;
			std::cout << "quando chega na 'casa' da senhora, percebe que na verdade é uma pequena cabana no meio de uma floresta\n" << std::endl;
			std::cout << "ao adentrar seus aposentos, a velha senhore lhe cura com estranhos liquidos(aparentemente algo comestivel)\n" << std::endl;
			std::cout << "seu corpo se cura rapidamente e sente-se com novos poderes\n" << std::endl;
			p.energia = p.energia * 5;
			std::cout << "a idosa se apresenta, seu nome é Lucy.\n" << std::endl;
			std::cout << "contando sua história, ela diz que seu filho era um bravo guerreiro que morrera lutando bravamente contra o rei demônio\n" << std::endl;
			std::cout << "como recompensa por sua coragem, você recebe o antigo equipamento de seu falecido filho, assim, podendo lutar, equilibradamente contra inimigos poderosos" << std::endl;
			p.energia = p.energia * 1.8;
			p.forcaFisica = p.forcaFisica * 2.5;
			p.forcaMagica = p.forcaMagica * 0.6;
			std::cout << "com a armadura e espada de um bravo guerreiro seus atributos sobem: " << std::endl;
			std::cout << "sua nova força física é " << p.forcaFisica << std::endl;
			std::cout << "com potentes defesas, sua vida máxima é elevada " << p.energia << std::endl;

		}
		if (opcao == 2)
		{
			std::cout << "após a luta, sua sobrevivência é duvidosa.\n" << std::endl;
			std::cout << "como forma de agradecimento, a senhora retira uma estranha esfera de sua bolsa e diz que será ultil de alguma forma\n" << std::endl;
			std::cout << "sua vida é curada completamente e você recebe equipamentos básicos de um mago, subindo assim, seus atributos\n" << std::endl;
			std::cout << "IDOSA: meu filho foi um bravo guerreiro outrora, infelizmente nao habita entre nós, creio que habilidades de um mago, com ataques a longa distância, seja algo que te ajudará a sobreviver!" << std::endl;
			std::cout << "sua força mágica aumenta: " << p.forcaMagica << std::endl;

		}

	}
}

void faseGothamCity(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Você chegou em Gotham City, vamos ver se conseguimos arranjar dinheiro para conseguirmos nos preparar melhor. Quem sabe não acabamos encontrando o Batman por aqui!" << std::endl;

		std::cout << "Olhe só, estão contratando temporariamente, pode ser uma boa para conseguirmos uma graninha a mais, o que acha?" << std::endl;

		std::cout << "1 - Claro\n2 - Nah, deixa queto" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Contratante: Olá cidadão de gotham city, você está atras de uma renda extra certo? Bem, venha comigo, estou precisando de um ajudante, é bem rapidinho." << std::endl;
		std::cout << "1 - Vamos la\n2 - To afim não, deu preguiça" << std::endl;

		std::cin >> opcao;

		unsigned int ganho = 0;

		switch (opcao)
		{
			case 1:

				std::cout << "Algum tempo depois..." << std::endl;
				std::cout << "Ufa! Acabamos, obrigado pela ajuda, não sei como eu faria isto sozinho, aqui está seu pagamento" << std::endl;

				ganho = geraAleatorio() * 100;

				p.creditos = p.creditos + ganho;

				p.energia = p.energia - 5;

				std::cout << "+ $" << ganho << std::endl;

				std::cout << "Conseguimos uma graninha a mais agora, podemos juntas para comprarmos comidas e armas, vamos descançar um pouco para recupermos energia após um longo dia de trabalho. E eu juro que vi o Batman em cima de algum predio..." << std::endl;
				break;

			case 2:
				std::cout << "Ah que pena, eu precisava mesmo de ajuda, boa sorte com sua jornada..." << std::endl;
				break;
		}
	}

	if (opcao == 2)
	{
		std::cout << "Ok né, qualquer coisa pedimos emprestado para alguem." << std::endl;
	}
}

void faseDaFloresta(struct Personagem &p)
{

	unsigned int opcao = -1;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Heroi... O rei demonio esta esperando por voce na cidade caida Lore! " << std::endl;
		std::cout << "Antes de poder confronta-lo, voce precisara� passar pela floresta obscura e derrotar as criaturas malignas que nela habitam.\n\n";

		std::cout << "Voce esta na entrada da floresta, nessa entrada h� dois estabelecimentos:\n\n1-Centro de treinamento\n2-Magic Shoppe\n3-Nada" << std::endl;
		std::cin >> opcao;

	}

	if (opcao == 1)
	{
		std::cout << "Salve bravo aventureiro! Eu sou mazumi um mago guerreiro." << std::endl;
		std::cout << "Quer aprender as habilidades que posso te ensinar?" << std::endl;
		std::cout << "Muito bem." << std::endl;
		std::cout << "Se voce VIVER durante minhas aulas, voce pode apenas me agradecer!\n" << std::endl;

		std::cout << "1-Mago\n2-Guerreiro\n3-Nada\n\n" << std::endl;
		std::cin >> opcao;

		if (opcao == 1)
		{

			if (p.creditos >= 1)
			{
				std::cout << "Parabéns, voc� adquiriu a Classe Mago, com ela se pode pegar as energias misticas do mundo ao seu redor e enviar fogo e gelo pelo campo de batalha!\n\n" << std::endl;
				p.creditos = p.creditos - 2;

				mostraStatusDoJogador(p);

			} else
			{
				std::cout << "Você não possui créditos o suficiente." << std::endl;
			}

		} else if (opcao == 2)
		{

			if (p.creditos >= 1)
			{
				std::cout << "Parabéns, voc� adquiriu a Classe Guerreiro, com  ela se pode ter um grande engajamento em combates corpo a corpo!\n\n" << std::endl;
				p.creditos = p.creditos - 2;

				mostraStatusDoJogador(p);

			} else
			{
				std::cout << "Você não possui créditos o suficiente." << std::endl;
			}

		} else
		{
			std::cout << "Que cara estranho....";
		}

	}
	//Division
	if (opcao == 2)
	{
		std::cout << "Eu sou o Warlic, bem-vindo a minha loja de magia! Sinta-se a vontade para examinar minha colecao requintada de itens magicos e pocoes." << std::endl;

		std::cout << "1-Nada\n2-Poc�es\n3-Armamento" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Po��o f�sica (Aumenta forca)\n2-Po��o magia (Aumenta a forca magica)" << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 2)
					{
						p.forcaFisica += 10;
						p.creditos -= 2;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 1)
					{
						p.forcaMagica += 10;
						p.creditos -= 1;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Holy avenger - Espada m�gica forjada com sangue de deuses, qualquer coisa que estre na frente de seu fio � destruido instantaneamente, sem direito a testes de resist�ncia.\n" << std::endl;
				std::cout << "2-super nova bow - Arco que tem a energia de uma estrela concentrada em s�, suas flechas evapora o que toca.\n";
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					std::cout << "Otima escolha guerreiro!\n\n";
					if (p.creditos >= 2)
					{
						p.forcaFisica += 200;
						p.creditos -= 2;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					std::cout << "Otima escolha guerreiro!\n\n";
					if (p.creditos >= 1)
					{
						p.forcaMagica += 200;
						p.creditos -= 1;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
			}
			return;
		}
	}

}

void faseBatalha(struct Personagem &p)
{
	unsigned int r, d;

	std::cout << "\nAp�s uma exaustiva caminhada sobre o sol" << std::endl;
	std::cout << "Voce decide descansar aos pes de uma grande arvore.No meio da noite, um barulho vindo da dire��o do mato te faz acordar" << std::endl;
	std::cout << "Com o cora��o acelerado voce avista uma pessoa, na qual esta amea�ando\n" << std::endl;
	std::cout << "O que voce faz?\n1-Batalha\n2-Corre\n3-Conversa\n";
	std::cin >> r;

	if (r == 1)
	{
		std::cout << "Furioso com a situa��o, voce aceita a batalha!!\n" << std::endl;
		std::cout << "Escolha seu movimento\n1-Soco na cara\n2-Chute na barriga\n3-Mordida na orelha" << std::endl;
		std::cin >> d;

		switch (d)
		{

			case 1:
				std::cout << "Seu soco faz cocegas no seu oponente" << std::endl;
				p.energia = -10;

				break;

			case 2:
				std::cout << "\nBela tentativa, mas seu chute foi bloqueado" << std::endl;
				p.energia = -10;

				break;

			case 3:
				std::cout << "Um golpe sujo, mas eficaz" << std::endl;
				std::cout << "Machucado, seu oponente foge da batalha!" << std::endl;
				break;

		}

	}

	if (r == 2)
	{

		std::cout << "Voce escapa daquela situa��o perigosa.Mas provaste que nao tem coragem suficiente para encarar esse mundo!!!" << std::endl;
		p.energia = p.energia - p.energia;

		return;
	}

	if (r == 3)
	{
		std::cout << "Para ele dialogo n�o � uma op��o!\n";

	}
}

void faseDaCaverna(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Voc� chegou na floresta e possui duas cavernas. Tem que decidir em qual entrar." << std::endl;
		std::cout << "1-Caverna Verde\n2-Caverna Azul" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Quando voc� entra possui dois ba�s e precisa escolher apenas uma." << std::endl;

		std::cout << "1-Detona\n2-Fraco\n3-Nenhum Ba�" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Machado voc� possuir� maior resistencia\n2-Lan�a voc� ter� um ataque potenteroso." << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 10)
					{
						p.energia += 30;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Toma vergonha e escolha algo." << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "Volte quando souber o que deseja.";
		}

	}

	if (opcao == 2)
	{
		std::cout << "Quando voc� entra possui dois ba�s e precisa escolher apenas uma." << std::endl;

		std::cout << "1-Fino Trato\n2-Gostosura\n3-Nenhum Ba�" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Faca voc� possuir� maior resistencia\n2-Porrete voc� ter� um ataque potenteroso." << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 10)
					{
						p.energia += 30;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Toma vergonha e escolha algo." << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "Volte quando souber o que deseja.";
		}
	}
}
//Fase Labirinto

std::vector<std::string> RemoverOpcao(char opcao, std::vector<std::string> direcao)
{
	std::vector<std::string> direcao2;
	for (int i = 0; i < direcao.size(); i++)
	{
		if (opcao != direcao[i][0])
		{
			direcao2.push_back(direcao[i]);
		}
	}
	return direcao2;
}

char PerguntarDirecao(std::vector<std::string> direcao)
{

	unsigned char opcao;
	std::cout << "Você pode escolher essas direções\n";
	for (int i = 0; i < direcao.size(); i++)
	{
		std::cout << direcao[i][0] << " - " << direcao[i] + "\n";
	}
	std::cout << "Qual direção você escolhe?\n";
	std::cin >> opcao;
	system("clear||cls");
	return opcao;
}

//Seleciona Direcao
bool escolherDirecao(bool direcaoCorreta, std::list<char> mapa)
{

	if (mapa.front() == 'X')
	{
		return true;
	} else
	{
		std::vector<std::string> direcao;

		direcao.push_back("Frente");
		direcao.push_back("Direita");
		direcao.push_back("Esquerda");

		bool ok = false;
		bool dC = false;

		do
		{
			if (direcaoCorreta)
			{
				do
				{
					switch (PerguntarDirecao(direcao))
					{
						case 'f':
						case 'F':
							direcao = RemoverOpcao('F', direcao);
							std::cout << "\nVocê decidiu seguir em frente! \n\n";
							if (mapa.front() == 'F')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						case 'd':
						case 'D':
							direcao = RemoverOpcao('D', direcao);
							std::cout << "\nVocê decidiu virar a direita! \n\n";
							if (mapa.front() == 'D')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						case 'e':
						case 'E':
							direcao = RemoverOpcao('E', direcao);
							std::cout << "\nVocê decidiu virar a esquerda! \n\n";
							if (mapa.front() == 'E')
							{
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
				if (escolherDirecao(dC, mapa))
				{
					return true;
				}

			} else
			{
				do
				{
					switch (PerguntarDirecao(direcao))
					{
						case 'f':
						case 'F':
							direcao = RemoverOpcao('F', direcao);
							std::cout << "\nVocê decidiu seguir em frente! \n\n";
							if (mapa.front() == 'F')
							{
								mapa.pop_front();
							}
							break;
						case 'd':
						case 'D':
							direcao = RemoverOpcao('D', direcao);
							std::cout << "\nVocê decidiu virar a direita! \n\n";
							if (mapa.front() == 'D')
							{
								mapa.pop_front();
							}
							break;
						case 'e':
						case 'E':
							direcao = RemoverOpcao('E', direcao);
							std::cout << "\nVocê decidiu virar a esquerda! \n\n";
							if (mapa.front() == 'E')
							{
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
					case 1:
						std::cout << "Você encontrou o fim desse caminho!\n";
						break;
					case 2:
						std::cout << "Não tem nada aqui!\n\n";
						break;
					case 3:
						std::cout << "Vozes desconhecidas...\n-Esse não é o seu caminho, volte antes que seja tarde demais!\n\n";
						break;
					case 4:
						std::cout << "Caminho sem saída!\n\n";
						break;
					case 5:
						std::cout << "Você andou... e andou... e percebeu que estava andando em círculo...\n\n";
						break;
					default:
						std::cout << "Você encontrou o fim desse caminho!\n\n";
						break;
				}

				if (direcao.size() == 0)
				{
					std::cout << "\nVocê percebeu que olhou todos os caminhos desse lado, então decidiu que deveria voltar e ir por um caminho diferente! \n\n";
					return false;
				} else
				{
					std::cout << "\nVocê voltou para o último ponto, antes de se perder, escolha outro caminho!!!\n\n";
				}
			}
			if (mapa.front() == 'X')
			{
				break;
			}
		} while (true);

	}

}

//Iniciar
void faseLabirinto(struct Personagem &p)
{
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
	if (escolherDirecao(true, mapa))
	{
		std::cout << "Você finalmente encontrou o coração do dragão! \n";
		p.forcaMagica = 60;
	}
}

void faseFlorestaGelida(struct Personagem &p, struct InimigosGelidos &g)
{

	std::cout << "Logo apos adquirir o -artefato magico-, nosso proximo destino sera a Floresta Gelida, o lar da pena de uma Fenix Glacial," << std::endl;
	std::cout << "que possui poderes magicos de bencaos, no qual me protegeria das criaturas da Floresta de Nederviersel." << std::endl;

	unsigned int opcao = 0;
	unsigned int esc;
	unsigned int luta = 0;

	while (opcao < 1 || opcao > 3)
	{
		std::cout << "Na entrada da floresta, ouvimos um som aterrorizador vindo do seu interior." << std::endl;
		std::cout << "Diz a lenda, que uma criatura perversa e gigantesca perambula por entre as arvores esguias, se escondendo na densa névoa causada pelo gelo." << std::endl;
		std::cout << "Ao adentrar na nevoa, percebo alguns vultos ao meu redor, que vao tomando forma de pequenas criaturas fofinhas." << std::endl;
		std::cout << "Ao observar sua fisionomia, decido qual sera minha atitude.\n" << std::endl;
		std::cout << "1 - Atacar \n2 - Deixar elas em paz \n3 - Tentar um contato amigavel" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Empunho minha arma e desfiro um golpe contra a criatura fofinha que se enfurece e me ataca, causando um dano fatal." << std::endl;
		if (g.danoFofo > 0)
		{
			std::cout << "Voce sucumbiu a investida de uma fera fofuxa." << std::endl;
		}
		return;
	}

	if (opcao == 2)
	{
		std::cout << "Apos deixar as ferinhas em paz, caminho sem rumo na esperança de encontrar o item sagrado." << std::endl;
		std::cout << "Vagueio por horas ate avistar o que poderia ser uma preguica das neves gigante, com vida de " << g.vidaP << " e dano de " << g.dano << " que logo nota minha presença e vem em minha direcao." << std::endl;
		std::cout << "-Pense rapido heroi-." << std::endl;

		std::cout << "1-Enfrentar\n2-Esconder\n3-Fugir" << std::endl;
		std::cin >> esc;

		switch (esc)
		{
			case 1:
				if (p.forcaFisica > g.vidaP)
				{
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

				} else if (p.forcaFisica < g.vidaP)
				{
					std::cout << "A preguica me machucou " << std::endl;
					p.energia = p.energia - g.dano;
					if (g.dano > p.energia)
					{
						std::cout << "Fui atropelado e morri." << std::endl;
						return;
					} else
					{
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
				} else
				{
					std::cout << "Batemos a cabeca e cada um foi para o seu lado sem dano." << std::endl;
					std::cout << "Depois de me recuperar da colisao, ainda tonto, segui em frente na minha jornada." << std::endl;
					std::cout << "Depois de muito tempo, cheguei a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
					std::cout << "Essa luz, A Pena de Fenix de Gelo, bem na minha frente." << std::endl;
					std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
					std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
					std::cout << "Ela se aproxima e uma luta começa pela posse do item sagrado" << std::endl;
					std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;
				}
				break;
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
	if (opcao == 3)
	{
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
	do
	{
		std::cout << "O que deseja fazer? \n1 - Ataque Fisico\n2 - Ataque Magico \n3 - Defender" << std::endl;
		std::cin >> luta;
		switch (luta)
		{
			case 1:
				if (g.vidaM < p.forcaFisica)
				{
					g.vidaM = 0;
				} else
				{
					g.vidaM = g.vidaM - p.forcaFisica;
					std::cout << "O Boss esta com " << g.vidaM << " de vida restante." << std::endl;
				}

				break;
			case 2:
				if (g.vidaM < p.forcaMagica)
				{
					g.vidaM = 0;
				} else
				{
					g.vidaM = g.vidaM - p.forcaMagica;
					std::cout << "O Boss esta com " << g.vidaM << " de vida restante." << std::endl;
				}
				break;
			case 3:
				if (p.energia < g.danoM)
				{
					p.energia = 0;
				} else
				{
					p.energia = (p.energia - g.danoM) - g.veneno;
					std::cout << "Voce esta com " << p.energia << " de vida, tomando mais " << g.veneno << " de dano venenoso" << std::endl;
				}
				break;
			default:
				std::cout << "Voce tem que decidir o que fazer, ficar parado ai nao vai te fazer um heroi." << std::endl;
		}
	} while (g.vidaM != 0 && p.energia != 0);
	if (g.vidaM == 0)
	{
		std::cout << "O inimigo morreu, vamos continura nossa jornada" << std::endl;
		p.creditos = p.creditos + g.dinheiro;
		p.forcaFisica = p.forcaFisica + 50;
		p.forcaMagica = p.forcaMagica + 50;
		mostraStatusDoJogador(p);
	}
	if (p.energia == 0)
	{
		std::cout << "Voce morreu, sua jornada acabou" << std::endl;
	}
	std::cout << "Conseguimos nossa Pena da Fenix Glacial, proxima parada, Floresta de Nederviersel." << std::endl;
}

void faseGuilda(struct Personagem &p)
{
	unsigned int escolha = -1;

	while (escolha < 1 || escolha > 2)
	{
		std::cout << "Você está andando pela floresta até que se depara com um recrutamento para magos." << std::endl;
		std::cout << "Então você decide emtrar." << std::endl;
		std::cout << "Ao entrar na guilda um poder foi-lhe consedido:" << std::endl;
		p.forcaMagica = p.forcaMagica + 10;
		std::cout << "Agora você tem uma força Mágica de " << p.forcaMagica << std::endl;
		std::cout << "Um velho mago lhe da as instruções: \n1-Você pode fazer missões, para ganhar orbites \n2-Ou então você pode fazer missões para ganhar intens mágicos." << std::endl;
		std::cin >> escolha;
	}

	if (escolha == 1)
	{
		std::cout << "Você tem duas missões: \n1-caçar um javali que esta atormentando a vila (nivel - facil) \n2-buscar o tesouro na torre do Dragão (nivel - difícil)" << std::endl;
		std::cin >> escolha;

		if (escolha == 1)
		{
			std::cout << "Chegando na vila você se depara com o javali." << std::endl;
			std::cout << "1-espantar \n2-matar." << std::endl;
			std::cin >> escolha;

			if (escolha == 1)
			{
				std::cout << "Você espanta o javali e volta para a guilda dos magos." << std::endl;
				p.creditos = p.creditos + 15;

				mostraStatusDoJogador(p);

				faseGuilda(p);
			} else if (escolha == 2)
			{
				std::cout << "Você golpeia o javali mantando-o" << std::endl;
				p.energia = p.energia - 5;
				p.creditos = p.creditos + 24;

				mostraStatusDoJogador(p);
			}
		} else if (escolha == 2)
		{
			std::cout << "Chegando na torre do dragão você encontra o tesouro com facilidade, mas logo em seguida um tenebroso dragão aparece! " << std::endl;
			std::cout << "Te dando duas opções:\n1-Fugir\n2-Lutar" << std::endl;
			std::cin >> escolha;

			if (escolha == 1)
			{
				std::cout << "Você então decidiu fugir? foi um erro!" << std::endl;
				std::cout << "Você infelizmente tropeça e cai pelas escadas da torre e o dragão atiça fogo pela boca em sua direção. o que você fará agora?" << std::endl;
				std::cout << "1-usar a magia para tentar se defender\n2-tentar se esquivar." << std::endl;
				std::cin >> escolha;

				switch (escolha)
				{
					case 1:
						if (p.forcaMagica >= 37)
						{
							std::cout << "Você conseguiu se defender e consequentemente fez o dragão adormecer e conseguiu sair do torre são e salvo..." << std::endl;
							std::cout << "Muito bem! Você conseguiu pegar o tesouro!" << std::endl;
							std::cout << "Você volta para a guilda dos magos." << std::endl;
							p.creditos = p.creditos + 41;

							mostraStatusDoJogador(p);
						} else
						{
							std::cout << "Você não tem magia o suficiente e então você morre!" << std::endl;
						}
						break;
					case 2:
						std::cout << "Você não é rápido o suficiente e então você morre!" << std::endl;
						break;
					default:
						std::cout << "Erro" << std::endl;
						break;
				}
			} else if (escolha == 2)
			{ //lutar com o dragao
				std::cout << "Você escolheu dar o primeiro golpe:\n1-Usar magia para enfrenta-lo\n2-Mudar de ideia e tentar domestica-lo" << std::endl;
				std::cin >> escolha;

				switch (escolha)
				{
					case 1:
						if (p.forcaFisica >= 40 && p.forcaMagica >= 30)
						{
							std::cout << "Você consegue atacar o dragão e corre para se esconder nos vão da torre." << std::endl;
							std::cout << "O dragão desnorteado começa a atear fogo em toda parte e começa a vir em sua direção.\nO que você fará agora?" << std::endl;
							std::cout << "1-usar a magia para tentar se defender\n2-tentar se esquivar." << std::endl;
							std::cin >> escolha;

							switch (escolha)
							{
								case 1:
									if (p.forcaMagica >= 37)
									{
										std::cout << "Você conseguiu se defender e consequentemente fez o dragão adormecer e conseguiu sair do torre são e salvo..." << std::endl;
										std::cout << "Muito bem! Você conseguiu pegar o tesouro!" << std::endl;
										std::cout << "Você volta para a guilda dos magos." << std::endl;
										p.creditos = p.creditos + 125;

										mostraStatusDoJogador(p);
									} else
									{
										std::cout << "Você não tem magia o suficiente e então você morre!" << std::endl;
									}
									return;
								case 2:
									std::cout << "Você não é rápido o suficiente e então você morre!" << std::endl;
									return;
								default:
									std::cout << "Erro" << std::endl;
									return;
							}
						} else
						{
							std::cout << "Você se cansa rápido e não tem forças o suficiente para enfrenta-lo" << std::endl;
						}
						break;
					case 2:
						std::cout << "Você tenta domestica-lo porém o dragão se irrita.\nVocê morre!" << std::endl;
						return;
					default:
						std::cout << "Erro" << std::endl;
						return;
				}
			}
		}
		return;
	}
	if (escolha == 2)
	{
		std::cout << "Você tem uma missão: \nIr até o castelo abandonado e pegar a joia do Fim" << std::endl;

		escolha = -1;

		if (escolha == -1)
		{
			std::cout << "No castelo você tem três alternativas\n1-Entrar pela porta da frente\n2-Entrar pelos fundos\n3-Criar sua propia entrada criando um portal" << std::endl;
			std::cin >> escolha;

			switch (escolha)
			{
				case 1:
					std::cout << "Ao entrar pela porta da frente, você cai em uma armadilha e\nVocê morre!" << std::endl;
					return;
				case 2:
					std::cout << "Ao entrar pela porta da frente, você se depara com um caminho suspeito e pode ser perigoso!\nFique atento!" << std::endl;
					std::cout << "1-Para desistir\n2-Para continuar" << std::endl;
					std::cin >> escolha;

					if (escolha == 1)
					{
						std::cout << "Você após procurar muito, desiste e vai embora de mãos vazias" << std::endl;
						p.energia = p.energia - 20;

						mostraStatusDoJogador(p);

					} else if (escolha == 2)
					{
						std::cout << "Você se depara com uma porta...mas ela esta emperrada\1-Ignorar\n2-Tentar abrir" << std::endl;
						std::cin >> escolha;
						if (escolha == 1)
						{
							std::cout << "Você após procurar muito, desiste e vai embora de mãos vazias" << std::endl;
							p.energia = p.energia - 20;

							mostraStatusDoJogador(p);
							return;
						} else if (escolha == 2)
						{
							if (p.forcaFisica >= 30)
							{
								std::cout << "Após muito esforço a porta se abre e você encontra a joia do fim!" << std::endl;
								std::cout << "Muito bem! Você conseguiu pegar a joia!" << std::endl;
								p.forcaMagica = p.forcaMagica + 16;

								mostraStatusDoJogador(p);
							} else
							{
								std::cout << "Você após procurar muito, desiste e vai embora de mãos vazias" << std::endl;
								p.energia = p.energia - 20;

								mostraStatusDoJogador(p);
							}
						}
					}
					return;
				case 3:
					if (p.forcaMagica >= 37)
					{
						std::cout << "Após muito esforço você consegue abrir um portal e na mais pura sorte você encontra a joia do fim!" << std::endl;
						if (p.forcaMagica >= 45)
						{
							std::cout << "Com o portal aberto você conseguiu pegar a joia! e sair com tranquilidade!" << std::endl;
							p.forcaMagica = p.forcaMagica + 16;

							mostraStatusDoJogador(p);
						} else
						{
							std::cout << "Mas, sua magia não se estabilizou e o portal fechou, e sua magia não é suficiente para abrir outro\nTendo somente uma saida: a porta emperrada!" << std::endl;
							if (p.forcaFisica >= 30)
							{
								std::cout << "Após muito esforço a porta se abre e você e você consegue sair!" << std::endl;
								std::cout << "Muito bem! Você conseguiu pegar a joia e sair são e salvo!" << std::endl;
								p.forcaMagica = p.forcaMagica + 16;

								mostraStatusDoJogador(p);
							} else
							{
								std::cout << "Após horas sem saber o que fazer você e você consegue uzar as suas forças magicas para usar a joia do fim e se teletransportar para fora do castelo!\n Porém ao sair, a joia se quebra e você sai de mãos vazias." << std::endl;

								mostraStatusDoJogador(p);
							}
							return;
						}
					} else
					{
						std::cout << "Sua magia não é suficiente para abrir esta passagem" << std::endl;
					}
					return;
				default:
					std::cout << "Erro" << std::endl;
					return;
			}
		}
	}
}

void faseTrapaceiros(struct Personagem &p)
{
	unsigned int opcao = -1;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Agora tu estás perambulando pelos campos e montanhas até que acidentalmente defronta-se com dois trapaceiros. Tu tens duas opções: " << std::endl;
		std::cout << "1-Indecisão\n2-Fujir" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		if (p.armamento == "")
		{
			std::cout << "Você vai na mão contra os trapaceiros..." << std::endl;
			p.creditos = p.creditos - p.creditos;
			std::cout << "Você foi roubado e agora possui " << "$" << p.creditos << " orbites" << std::endl;

			if (p.creditos <= 5)
			{
				std::cout << "Você sai andando desanimado, e encontra uma mulher pela qual, deixou cair uma joia no chão." << std::endl;
				std::cout << "Você tem duas alternativas:" << std::endl;
				std::cout << "1-Devolver para ela\n2-Roubar a joia" << std::endl;
				std::cin >> opcao;

				switch (opcao)
				{
					case 1:
						std::cout << "Você grita para a ela e a devolve a joia." << std::endl;
						std::cout << "Ela muito agradescida lhe-da uma recompensa de $26 orbites" << std::endl;
						p.creditos = p.creditos + 26;

						mostraStatusDoJogador(p);

						std::cout << "Então tu poderá voltar para a cidade ou continuar vossa jornada..." << std::endl;
						std::cout << "1-voltar para a cidade\n2-continuar jornada" << std::endl;
						std::cin >> opcao;

						if (opcao == 1)
						{
							faseDaCidade(p);
						} else if (opcao == 2)
						{
							std::cout << "Tu continuas vosso caminho..." << std::endl;
						}
						return;
					case 2:
						std::cout << "Você pega a joia e vai para um comércio." << std::endl;
						std::cout << "O vendedor te olha e pergunta: O que tens para mim meu jovem ?" << std::endl;
						std::cout << "Tu mostra para ele a joia e o comerciante te faz duas ofertas:" << std::endl;
						std::cout << "1-Compro esta joia de ti por $30 Orbites\n2-Compro esta joia de ti por uma poção de Força Mágica" << std::endl;
						std::cin >> opcao;
						if (opcao == 1)
						{
							p.creditos = p.creditos + 30;

							mostraStatusDoJogador(p);

							std::cout << "Então tu poderá voltar para a cidade ou continuar vossa jornada..." << std::endl;
							std::cout << "1-voltar para a cidade\n2-continuar jornada" << std::endl;
							std::cin >> opcao;

							if (opcao == 1)
							{
								faseDaCidade(p);
							} else if (opcao == 2)
							{
								std::cout << "Tu continuas vosso caminho..." << std::endl;
							}
							return;

						} else if (opcao == 2)
						{
							p.forcaMagica = p.forcaMagica + 9;

							mostraStatusDoJogador(p);

							std::cout << "Então tu poderá voltar para a cidade ou continuar vossa jornada..." << std::endl;
							std::cout << "1-voltar para a cidade\n2-continuar jornada" << std::endl;
							std::cin >> opcao;

							if (opcao == 1)
							{
								faseDaCidade(p);
							} else if (opcao == 2)
							{
								std::cout << "Tu continuas vosso caminho..." << std::endl;
							}
							return;

						}
						break;
					default:
						std::cout << "Erro" << std::endl;
						break;
				}
			}

		} else
		{
			std::cout << "Tu sacas vosso(a) " << p.armamento << " e intimida os trapaceiros" << std::endl;
			std::cout << "Eles não se intimidam e partem para cima. Tu tens a oportunidade de matá-los, o que tu farás?" << std::endl;
			std::cout << "1-Os Matarei\n2-Os Imobilizarei" << std::endl;
			std::cin >> opcao;

			if (opcao == 2)
			{
				opcao = 0;

				while (opcao < 1 || opcao > 2)
				{
					std::cout << "A partir de qual parte do corpo desejas tu imobilizar os dois trapaceiros?" << std::endl;
					std::cout << "1-A partir da cabeça\n2-A partir das pernas" << std::endl;
					std::cin >> opcao;

					switch (opcao)
					{
						case 1:
							if (p.forcaFisica >= 30)
							{
								p.energia -= 70;
								p.creditos -= 20;
								std::cout << "Você os imobilizou e continuou a vossa jornada" << std::endl;
							} else
							{
								std::cout << "Desculpe, mas não dá..." << std::endl;
							}
							break;
						case 2:
							if (p.forcaFisica >= 15)
							{
								p.energia += 50;
								p.creditos -= 10;
								std::cout << "Você os imobilizou e continuou a vossa jornada" << std::endl;
							} else
							{
								std::cout << "Desculpe, mas não dá..." << std::endl;
							}
							break;
						default:
							std::cout << "Erro" << std::endl;
							break;
					}
					return;
				}
			} else if (opcao == 1)
			{
				std::cout << "Preparem-se para morrerem, indolentes!!!" << std::endl;
				p.energia = p.energia - p.energia;
				std::cout << "Eles morrem e tu continuas vosso caminho..." << std::endl;
				return;
			} else
			{
				std::cout << "Não farás nada? (...)";
				return;
			}
		}
	}
	if (opcao == 2)
	{
		std::cout << "Você então decidiu fujir? foi um erro!" << std::endl;
		std::cout << "Você infelizmente tropeça e é capturado pelos dois trapaceiros. O que farás agora?" << std::endl;

		std::cout << "1-Pedir redenção\n2-Escapar\n3-Tentar matá-los" << std::endl;
		std::cin >> opcao;

		if (opcao == 1)
		{
			std::cout << "Eles nunca lhe darão redenção!" << std::endl;
		} else if (opcao == 3)
		{
			std::cout << "Você sorrateiramente puxa uma faquinha escondida em suas vestes, infelizmente um trapaceiro percebe e te nocauteia" << std::endl;

			if (p.energia >= 60)
			{
				std::cout << "Você perdeu 60 pontos de energia!..." << std::endl;
				p.energia = p.energia - 60;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Você infelizmente morreu!!!" << std::endl;
			}
		} else if (opcao == 2)
		{
			std::cout << "Ao fugir, você chega até um desfiladeiro, um local sem saida, escorrega e cai..." << std::endl;
		} else
		{
			std::cout << "Não fará nada?" << std::endl;
		}
	}

}

void faseDaMasmorra(struct Personagem &p)
{

	unsigned int opcao = 0;

	std::cout << "Parabéns, após tanto suor e luta você chegou a masmorra," << std::endl;
	std::cout << "mas achando que a vida é um morango? Vai jovem pigmeu escolha um desses 3 caminhos." << std::endl;
	std::cout << "1-Esquerda\n2-Direita\n3-Meio" << std::endl;
	std::cin >> opcao;

	if (opcao == 1)
	{
		std::cout << "VocÃƒÂª estÃƒÂ¡ em um tunel e ele estÃƒÂ¡ ficando cada vez mais apertado," << std::endl;
		std::cout << "vocÃƒÂª precisa abrir uma porta para escapar, mas pra isso voÃƒÂ§ÃƒÂª precisa decifrar o enigma:" << std::endl;

		do
		{

			std::cout << "Sempre quando chego trago a tristeza\nMas sempre chego na hora certa\n" << std::endl;
			std::cout << "As vezes venho depois de uma doenÃƒÂ§a\nE outras, depois de um ato de violÃƒÂªncia\n" << std::endl;

			std::cout << "1-Vento\n2-Morte\n3-Arroz" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - 50;

					std::cout << "Sua escolha nÃƒÂ£o foi das mais sabias, volte e tente novamente" << std::endl;

					if (p.energia < 50)
					{
						p.energia = 0;
						return;
					}
					break;

				case 2:
					std::cout << "Parabéns jovem pigmeu, você passou de fase" << std::endl;

					break;

				case 3:
					p.energia = p.energia - 10;
					std::cout << "Sua escolha nÃƒÂ£o foi das mais sabias, volte e tente novamente" << std::endl;

					if (p.energia < 10)
					{
						p.energia = 0;
						return;
					}
					break;

				default:
					std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

			}

		} while (opcao != 2);

		opcao = 0;

		do
		{

			std::cout << "VoÃƒÂ§ÃƒÂª entrou em um labirinto com 3 caminhos, escolha um caminho:" << std::endl;

			std::cout << "1-Caminho escuro\n2-Caminho claro\n3-Caminho barulhento" << std::endl;

			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - p.energia;
					std::cout << "VocÃƒÂª caiu em um poÃƒÂ§o de lava" << std::endl;
					return;

				case 2:
					std::cout << "Boa noiticia, você não está morto" << std::endl;
					break;

				case 3:
					p.energia = p.energia - 10;
					std::cout << "3:Sua escolha nÃƒÂ£o foi das mais sabias, volte e tente novamente" << std::endl;
					if (p.energia < 10)
					{
						p.energia = 0;
						return;
					}
					break;

				default:
					std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

			}

		} while (opcao != 2);
		opcao = 0;

		do
		{

			std::cout << "VocÃƒÂª estÃƒÂ¡ em uma sala com trÃƒÂªs alavancas, acione elas na ordem correta para abrir a porta\n" << std::endl;

			std::cout << "1-dica: NÃƒÂ£o sou a ultima, e nem a primeira." << std::endl;
			std::cout << "2-dica: A contagem comeÃƒÂ§a por mim" << std::endl;
			std::cout << "3-dica: Sou maior que 1 e menor que 4" << std::endl;

			std::cout << "1: 1,3,2\n" << std::endl;
			std::cout << "2: 3,1,2\n" << std::endl;
			std::cout << "3: 2,1,3" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - 8;
					if (p.energia < 8)
					{
						p.energia = 0;
						return;
					}
					break;

				case 2:
					p.energia = p.energia - 10;
					if (p.energia < 10)
					{
						p.energia = 0;
						return;
					}
					break;

				case 3:
					std::cout << "Olha olha, você está me surpreendendo" << std::endl;
					break;

				default:
					std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

			}

		} while (opcao != 3);
		return;
	}

	if (opcao == 2)
	{
		std::cout << "VocÃª estÃ¡ em um tunel subaquÃ¡tico e precisa nadar para sobreviver" << std::endl;

		do
		{

			std::cout << "Escolha uma direÃ§Ã£o, esquerda ou direita" << std::endl;

			std::cout << "1-Esquerda\n2-Direita" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - 25;
					std::cout << "VocÃª encontrou uma criatura aquÃ¡tica mitolÃ³gica" << std::endl;

					if (p.energia < 25)
					{
						p.energia = 0;
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

		while (opcao != 2);

		opcao = 0;

		do
		{

			std::cout << "VocÃª acabou sendo envenenado durante a sua ultima jornada, mas tenho uma boa noiticia,\n" << std::endl;
			std::cout << "Na sua frente tem dois potes, porÃ©m sÃ³ um deles Ã© o antidoto pra o veneno.Escolha um pote:" << std::endl;

			std::cout << "1- O grande\n2- O pequeno" << std::endl;

			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - p.energia;
					std::cout << "Ops pote errado, Ã© apenas Ã¡gua, vocÃª nÃ£o resistiu" << std::endl;
					return;

				case 2:
					std::cout << "Boa escolha pequeno gafanhoto, o veneno nÃ£o estÃ¡ mais em seu corpo,\n" << std::endl;
					std::cout << "agora vocÃª pode seguir seu caminho" << std::endl;
					break;

				default:
					std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

			}

		} while (opcao != 2);
		opcao = 0;

		do
		{

			std::cout << "VocÃª encontrou uma bruxa que estÃ¡ disposta a te ajudar com a sua jornada,\n" << std::endl;
			std::cout << "Deseja aceitar a sua ajuda?\n" << std::endl;

			std::cout << "1-Sim" << std::endl;
			std::cout << "2-NÃ£o" << std::endl;

			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - p.energia;
					std::cout << "VocÃª nÃ£o deu ouvidos a sua mÃ£e quando ela disse que bruxas nÃ£o sÃ£o confiavÃ©s,\n" << std::endl;
					std::cout << "Agora ela te jogou em feitiÃ§o" << std::endl;
					return;

				case 2:
					p.energia = p.energia - p.energia;
					std::cout << "VocÃª resolveu lembrar de sua mÃ£e e nÃ£o deu ouvidos a bruxa, porÃ©m era tarde de mais,\n" << std::endl;
					std::cout << "VocÃª estÃ¡ preso em uma areia movediÃ§a" << std::endl;
					return;

				default:
					std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

			}

		} while (opcao != 4);

		return;
	}

	if (opcao == 3)
	{
		std::cout << "VocÃª estÃ¡ em um salÃ£o escuro com dois caminhos, escolha um deles:" << std::endl;

		do
		{

			std::cout << "Escolha um caminho, esquerda ou direita" << std::endl;

			std::cout << "1-Esquerda\n2-Direita" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{

				case 1:

					std::cout << "Otima escolha, esse caminho parece ser seguro" << std::endl;
					break;

				case 2:
					std::cout << "NÃ£o foi uma boa escolha, espinhos afiados sairam da parede e fizeram de vocÃª uma penera" << std::endl;
					p.energia = p.energia - p.energia;
					return;

				default:
					std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;
			}

		}

		while (opcao != 1);
	}

	opcao = 0;

	do
	{

		std::cout << "Você está em frente a uma porta, mas derepente começa subir uma fumaça tóxica,\n" << std::endl;
		std::cout << "Você precisa escolher entre voltar, ou tentar achar uma saida" << std::endl;

		std::cout << "1- Voltar:\n2- Achar outra saida" << std::endl;

		std::cin >> opcao;

		switch (opcao)
		{

			case 1:
				p.energia = p.energia - p.energia;
				std::cout << "Não foi uma boa escolha, o caminho estava fechado" << std::endl;
				return;

			case 2:
				std::cout << "Você foi corajoso e achou uma pequena fresta na parede e conseguiu escapar" << std::endl;
				break;

			default:
				std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

		}

	} while (opcao != 2);
	opcao = 0;

	do
	{

		std::cout << "Você acaba encuralado por um esqueleto com uma espada encantada e precisa batalhar com ele,\n" << std::endl;
		std::cout << "Escolha sua arma:" << std::endl;

		std::cout << "1-Graveto" << std::endl;
		std::cout << "2-Espada" << std::endl;

		std::cin >> opcao;

		switch (opcao)
		{

			case 1:
				p.energia = p.energia - p.energia;
				std::cout << "É serio que você fez essa escolha jovem gafanhoto? Nem preciso falar que você morreu néh" << std::endl;

				return;

			case 2:
				p.energia = p.energia - p.energia;
				std::cout << "Boa escolha, porém após tantos obstáculos você está muito fraco para batalhar e" << std::endl;

				return;

			default:
				std::cout << "OpÃƒÂ§ÃƒÂ£o invalida" << std::endl;

		}

	} while (opcao != 3);
	std::cout << "NarraÃ§Ã£o blabla" << std::endl;
	p.energia = p.energia - p.energia;
	return;
}

void faseDaDungeon(struct Personagem &p)
{
	//Escolha das missões
	int resposta = 0;
	int repetir;
	unsigned int menu = 0;
	unsigned int escolha = 0;

	while (escolha < 1 || escolha > 2)
	{
		std::cout << "Depois de sair Você vê um quadro de missões, nele só tem 2 papeis. Deseja olhar eles? \n";
		std::cout << "1-Sim\n2-Não";
		std::cin >> escolha;
	}

	if (escolha == 1)
	{
		for (;;)
		{
			std::cout << "Digite 1-MISSÃO DE ALTO NIVEL\n 2-MISSÃO BAIXO NIVEL";

			std::cin >> escolha;
			std::cout << "--------------------------------";

			if (escolha == 1)
			{
				std::cout << "MISSÃO DE ALTO NIVEL!!!" << std::endl;
				std::cout << "RECOMPENSA DE 200 CRÉDITOS" << std::endl;
				std::cout << "Objetivo:Matar todos os Esqueletos!" << std::endl;
				std::cout << "Existe uma Dungeon dos Esqueletos de Schrödinger que precisa ser destruida antes que sejá tarde, eles são muito fortes então tomem cuidado ao tentar destruir o lugar\n" << std::endl;
				std::cout << "Se desejar ir basta seguir pelo caminho das Árvores Mortas que está ao lado da entrada para a cidade.\n" << std::endl;
			} else if (escolha == 2)
			{
				std::cout << "MISSÃO DE BAIXO NIVEL -_-" << std::endl;
				std::cout << "RECOMPENSA DE 70 CRÉDITOS" << std::endl;
				std::cout << "Objetivo:Destruir todos os Slimes!" << std::endl;
				std::cout << "Perto da cidade existem um campo aberto onde varios Slimes estão vivendo, eles não fazem mal a ninguém, mas estão sujando e assustando alguns moradores da cidade\n" << std::endl;
				std::cout << "Eles são bem fraquinhos então são bem faceis de serem derrotados\n" << std::endl;
				std::cout << "Caso aceite o caminho para o lugar é logo depois da saida da cidade.\n " << std::endl;
			}
			repetir = 0;
			std::cout << "Se você desejar ler a outra missão digite 1 se não digite 2 para escolher uma delas" << std::endl;
			std::cin >> repetir;

			if (repetir == 2)
			{
				break;
			}
		}
		escolha = 0;

		std::cout << "Agora precisa decidir qual delas você escolhe?\n 1-Missão de Alto nivel\n 2-Missão de baixo nivel" << std::endl;
		std::cin >> escolha;

		if (escolha == 1)
		{
			escolha = 0;
			std::cout << "ok então você realmente é ganancioso hehe\n" << std::endl;
			std::cout << "Então você volta para o começo da cidade e desce o caminho das Árvores Mortas e vai percebendo que o ambiente está ficando estranho e cinza\n" << std::endl;
			std::cout << "Depois de um bom tempo andando você chega em uma dungeon bem grande e você vê uma porta\n deseja bater?" << std::endl;
			std::cout << "1 - sim 2 - não" << std::endl;
			std::cin >> escolha;
			if (escolha == 1)
			{
				std::cout << "Você vai chegando perto e o clima fica cada vez mais tenso\n" << std::endl;
				std::cout << "Você bate..." << std::endl;
				std::cout << "..." << std::endl;
				escolha = 0;
				std::cout << " POW POW os esqueletos derrubam a porta e vão para cima de você" << std::endl;
				std::cout << "1 - correr\n 2- lutar?\n" << std::endl;
				std::cin >> escolha;
				switch (escolha)
				{
					case 1:
						std::cout << "Você vira e tenta correr, porém uma flecha te acerta bem no peito." << std::endl;
						std::cout << "Você morreu de hemorragia kkkk" << std::endl;
						std::cout << "Tente novamente!!" << std::endl;
						return;
					case 2:
						std::cout << "Lutar? kkkkk como que luta sem espada?" << std::endl;
						std::cout << "Os esqueletos te cercam e enfiam as espadas em você" << std::endl;
						std::cout << "Você morreu kkkkk -_-" << std::endl;
						std::cout << "Tente novamente!!" << std::endl;
						return;

					default:
						std::cout << "Você fica parado e eles te cercam e te matam a espadadas" << std::endl;
						std::cout << "Você morreu kkkkkkkk -_-" << std::endl;

						return;
				}
			}
			if (escolha == 2)
			{
				escolha = 0;
				std::cout << "De dentro da porta você ouve uma voz" << std::endl;
				std::cout << "Responda uma pergunta, acertando poderá entrar errando morrerá. " << std::endl;
				std::cout << "Você reposnde? 1-sim 2-não";
				std::cin >> escolha;
				if (escolha == 1)
				{
					std::cout << "A pergunta é com quantos paus se fazem uma canoa?" << std::endl;
					std::cout << "1- Um só\n 2-300\n 3-Não sei nunca fiz uma canoa" << std::endl;
					std::cin >> resposta;
					switch (resposta)
					{
						case 1:
							std::cout << "Errado\n você recebe um flechada e morre" << std::endl;
							return;
						case 2:
							std::cout << "Errado\n você recebe 2 flechas no peito e morre" << std::endl;
							return;
						case 3:
							std::cout << "Bom como você acertou te deixarei entrar, MAS é por sua conta e risco" << std::endl;
							break;

						default:
							std::cout << "falou errado perdeu a vez" << std::endl;
							return;
					}
				}
				escolha = 0;
				std::cout << "Agora a porta está aberta em sua frente deseja entrar?\n 1-sim 2-não" << std::endl;
				std::cin >> escolha;
				if (escolha == 1)
				{
					std::cout << "Voce entrou dentro na dungeon" << std::endl;
					std::cout << "É um salão grande e escuro, aporta se fechou atrás de você, não tem como escapar" << std::endl;
					std::cout << "Você da mais alguns passos e POW POW POW de novo,\n esqueletos por toda a parte estão saindo não ah o que ser feito" << std::endl;
					std::cout << "Você morreu -_- " << std::endl;
					return;

				} else if (escolha == 2)
				{
					std::cout << "você fica parado quando derrepente toma 3 flechadas de alguns esqueletos que estavam andando pelo lugar" << std::endl;
					return;

				}
				if (escolha == 2)
				{
					std::cout << "Já que você não quer responder começa o game de novo ai" << std::endl;
					return;
					//p.energia = p.energia - p.energia;
				}
			}

		}
		if (escolha == 2)
		{
			std::cout << "Você vai ao final da cidade e anda um pouco por uma estrada,\n o ambiente é bem agradavel." << std::endl;
			std::cout << "andando mais um pouco você encontra um campo bem aberto, onde você acha os Slimes que as pessoas tanto desgostam" << std::endl;
			std::cout << "Eles parecem muito amigaveis você realmente deseja exterminar todos eles\n aparentemente só de chegar perto com a mão levantanda para bater eles já se assustam" << std::endl;
			std::cout << "Tente espantalos com gritos e movimentos brucos" << std::endl;
			std::cout << "1- gritar e correr atrás deles 2-não fazer nada 3 - socar " << std::endl;
			escolha = 0;
			std::cin >> escolha;
			switch (escolha)
			{
				case 1:
					std::cout << "Você grita e corre na direção deles, as pessoas que estavam perto te veem gritando e correndo." << std::endl;
					std::cout << "Os Slimes correm de medo de você e vão para o meio da floresta e provavelmente vão demorar muito tempo para voltar" << std::endl;
					std::cout << "Você volta para a cidade e ganha seu dinheiro" << std::endl;
					p.creditos = p.creditos + 70;
					mostraStatusDoJogador(p);
					std::cout << "Obrigado por jogar XD" << std::endl;

					return;
				case 2:
					std::cout << "... o que você queria que acontecesse??" << std::endl;
					return;

				case 3:
					std::cout << "Você anda para o Slime mais proximo e da um SOCASSO na cara dele,\n ele sai rolando e fica muito triste e vai embora, os outros o acompanham" << std::endl;
					std::cout << "Você volta para a cidade e ganha seu dinheiro" << std::endl;
					p.creditos = p.creditos + 70;
					mostraStatusDoJogador(p);
					std::cout << "Obrigado por jogar XD" << std::endl;
					return;

				default:
					std::cout << "Faz direito ai" << std::endl;
					return;
			}

		}

	} else if (escolha == 2)
	{
		std::cout << "Precisa ler as missões se não você não joga boa sorte e tente novamente." << std::endl;

	}
}

int main(int argc, char **argv)
{
	// s = seed rand = aleatório
	// std::time vem da biblioteca ctime
	std::srand(std::time(nullptr));	//<-- Retorno o Unix time stamp

	struct Personagem j = boasVindasDoJogo();
	struct InimigosGelidos g = faseFlorestaGelida();

	std::cout << "Você recebeu um presente das divindades da terra!\n";
	std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Cidade" << std::endl;
	faseDaCidade(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Labirinto" << std::endl;
	//faseLabirinto(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Caverna" << std::endl;
	faseDaCaverna(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Batalha" << std::endl;
	faseBatalha(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Floresta" << std::endl;
	faseDaFloresta(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Gothan City" << std::endl;
	faseGothamCity(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "A velha" << std::endl;
	faseDaVeinha(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Floresta gélida" << std::endl;
	faseFlorestaGelida(j, g);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Guilda" << std::endl;
	faseGuilda(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Trapaceiros" << std::endl;
	faseTrapaceiros(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Masmorra" << std::endl;
	faseDaMasmorra(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Dangeon" << std::endl;
	faseDaDungeon(j);

	mostraStatusDoJogador(j);
}

