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

float geraAleatorio()
{
	return rand() / (float) RAND_MAX;
}

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
		unsigned int vida;
		unsigned int energia;
		unsigned int altura;
		unsigned int forcaFisica;
		unsigned int forcaMagica;
		unsigned int creditos;
		unsigned int habilidadesMagicas;
		unsigned int vidaDoBrendon;
};

// 1/2 Estrutura Inimigo
struct Inimigo
{
		std::string nome;
		unsigned int vida;
		unsigned int forcaFisica;
		unsigned int forcaMagica;
		unsigned int habilidadesMagicas;
		unsigned int Gdano;
		unsigned int Pdano;
};

struct Inimigo faseDaMontanha()
{
	struct Inimigo i;
	i.forcaMagica = 100;
	i.forcaFisica = geraAleatorio() * 120;
	i.habilidadesMagicas = 100;
	i.vida = 150;
	i.Gdano = (geraAleatorio() * 99) + 2;
	i.Pdano = geraAleatorio() * 40;

	return i;
}

struct inimigoFloresta faseDaFloresta()
{
	struct inimigoFloresta f;

	f.energia = 200;
	f.forcaFisica = 50;
	f.forcaMagica = 50;
	f.creditos = geraAleatorio() * 50;
	return f;
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
	std::cout << "Voce esta em um mundo onde a fic????o ?? a realidade, \n";
	std::cout << "Com isso o mundo esta sobre amea??a de um ser poderoso chamado Leno Brega\n";
	std::cout << "ele busca migrar o reino de hyako para sua cole????o de planetas no sistema solar de bueno...\n";

	std::cout << "n??s de hyako secret room somos seres poderosos,porem ainda n??o podemos contra Leno brega\n";
	std::cout << "Por isso te convocamos aqui neste mundo,sabemos que voce podera nos ajudar...\n";
	std::cout << "Voce ?? a nossa unica salva????o,nos diga quem ?? voce.\n";

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
	eu.vidaDoBrendon = (geraAleatorio() * 1000) + 300;
	eu.creditos = 26;

	return eu;
}

void mostraStatusDoJogador(struct Personagem &p)
{

	if (p.energia == 0)
	{
		std::cout << "press f to pay respect" << std::endl;
		return;
	} else if (p.vidaDoBrendon == 0)
	{
		std::cout << "Brendon est?? morto" << std::endl;
	}

	std::cout << "Voc?? agora tem " << p.altura / 100.0 << " metros de altura, " << p.energia << " de energia com uma for??a de intensidade " << p.forcaFisica << " e um poder m??gico de " << p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaFloresta2(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 3)
	{
		std::cout << "Voc?? est?? na floresta, a sua frente tem dois caminhos com neblina, no da direita parece que ?? poss??vel ver uma cabana, no esquerdo, considerando que h?? mais neblina, ?? poss??vel que tenha alguma fonte de ??gua.\nPara onde voc?? deseja ir?" << std::endl;
		std::cout << "1-Direita\n2-Esquerda\n3-Retornar a fase da cidade" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "?? mesmo uma cabana abandonada, olhe...h?? uma fada em um pote, ajud??-a, quem sabe ela possa te recompensar.\nFada diz: Obrigada por me libertar guerreiro, o que posso fazer por voc?? como forma de agradecimento?" << std::endl;

		std::cout << "1-Nada, fico feliz por t??-la ajudado\n2-Preciso de uma arma mais forte\n3-D??-me mais energia" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 3)
			{
				std::cout << "1-Uma espada flamejante \n2-um escudo congelante" << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					std::cout << "Fada diz: ??tima escolha, isso lhe ajudar?? a acabar com aqueles que cruzarem seu caminho." << std::endl;
					p.forcaFisica = p.forcaFisica + 7;
					std::cout << "A intensidade de sua for??a foi aumentada em 7 pontos com esta aquisi????o, sendo ela agora de intensidade: " << p.forcaFisica << std::endl;

					break;

				case 2:
					std::cout << "Fada diz: Muito bem, aqui est?? o escudo que te proteger?? contra seus combatentes." << std::endl;
					p.forcaFisica = p.forcaFisica + 3;
					std::cout << "A intensidade de sua for??a foi aumentada em 3 pontos com esta aquisi????o, sendo ela agora de intensidade: " << p.forcaFisica << std::endl;
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Fada diz: Posso lhe conceder mais 5 pontos de energia." << std::endl;
			p.energia = p.energia + 5;
			std::cout << "A intensidade de sua energia foi aumentada conforme a promessa da fada e agora voc?? passou a ter uma energia de: " << p.energia << " pontos" << std::endl;
			return;
		} else
		{
			std::cout << "Fada diz: Muito obriga por me libertar, voc?? salvou a minha vida, desejo-lhe sorte em sua miss??o!" << std::endl;
		}

	}

	if (opcao == 2)
	{
		std::cout << "Est?? dif??cil enxergar com tanta neblina, mas parece mesmo um lago, o que deseja fazer?" << std::endl;

		std::cout << "1-Retornar para a floresta \n2-Atravessar a nado \n3-Usar for??a m??gica para se transportar para o outro lado do lago" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{
			std::cout << "Para esta miss??o ?? necess??ria uma for??a f??sica m??nima de intensidade 20." << std::endl;

			if (p.forcaFisica >= 20)
			{
				std::cout << "Sua for??a f??sica atual ?? de: " << p.forcaFisica << ".\nE caso execute esta miss??o ela lhe diminuir?? esta for??a em 4 pontos.\nDeseja continuar?\n1-Sim\n2-N??o" << std::endl;
				std::cin >> opcao;

				switch (opcao)
				{
					case 1:
						p.forcaFisica = p.forcaFisica - 4;
						std::cout << "Travessia conclu??da com sucesso!\nA intensidade de sua for??a f??sica foi diminu??da em 4 pontos, sendo ela agora de intensidade: " << p.forcaFisica << std::endl;
						break;

					case 2:
						std::cout << "Realmente, n??o parecia um bom neg??cio!\nRetorne para a floresta e veja se encontra um caminho mais f??cil." << std::endl;
						break;
				}

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Sua for??a f??sica atual ?? de: " << p.forcaFisica << "\nVoc?? n??o possui for??a f??sica suficiente para esta miss??o!!" << std::endl;
			}

		} else if (opcao == 3)
		{
			std::cout << "Para esta miss??o ?? necess??ria uma for??a m??gica m??nima de 30 orbites.";
			if (p.forcaMagica >= 30)
			{
				std::cout << "\nSua for??a m??gica atual ?? de: " << p.forcaMagica << "\nE caso execute esta miss??o ela lhe diminuir?? a for??a m??gica em 10 orbites\nDeseja continuar?\n1-Sim\n2-N??o" << std::endl;
				std::cin >> opcao;

				switch (opcao)
				{
					case 1:
						p.forcaMagica = p.forcaMagica - 10;
						std::cout << "Travessia conclu??da com sucesso!\nA intensidade de sua for??a m??gica foi diminu??da em 10 pontos, sendo ela agora de: " << p.forcaMagica << " orbites" << std::endl;
						break;

					case 2:
						std::cout << "Realmente, n??o parecia um bom neg??cio!\nRetorne para a floresta e veja se encontra um caminho mais f??cil." << std::endl;
						break;
				}

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Sua for??a m??gica atual ?? de: " << p.forcaMagica << "\nVoc?? n??o possui for??a m??gica suficiente para esta miss??o!!" << std::endl;
			}
		} else
		{
			std::cout << "Parece que algu??m aqui ficou com medinho!" << std::endl;
		}
	}

	if (opcao == 3)
	{
		std::cout << "Voc?? retornou a fase da cidade" << std::endl;

	}

}

void faseDaCidade(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "voce est?? no quarto principal do reino, neste quarto voce ve duas portas: Uma porta te levara at?? a tenda e a outra porta te levara at?? uma loja de equipamentos.\n Que porta voce escolhera?" << std::endl;
		std::cout << "1-Tenda\n2-Loja de equipamentos" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;

		std::cout << "1-Nada\n2-Comida\n3-esferas do drag??o" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Bife Acebolado (D?? muita energia)\n2-Banana Frita (D?? pouca energia)" << std::endl;
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
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Esqueci,elas n??o est??o a venda!!!" << std::endl;
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

		std::cout << "1-N??o rapai\n2-kamado nichirin\n3-Death Note" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			std::cout << "Voc?? tem bons olhos,porem n??o tem figuras suficientes inbecil" << std::endl;

			if (p.creditos >= 200)
			{
				std::cout << "Muitos Onis cair??o por essa Katana!!" << std::endl;
				p.creditos = p.creditos - 200;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Voc?? n??o merece esta Katana,domine sua respira????o primeiro!!" << std::endl;
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
		std::cout << "ao iniciar sua jornada, saindo de seu vilareijo calmo e pac??fico," << std::endl;
		std::cout << "essa ?? a realidade da grande maioria dos 'herois\n'" << std::endl;
		std::cout << "ap??s se distanciar relativamente de sua terra natal, voc?? encontra um grupo de jovens, cuja apar??ncia se assemelha aos seguidores do rei Dem??nio\n" << std::endl;
		std::cout << "eles est??o espancando uma senhora de apar??ncia duvidosa\n voc?? possui tr??s op????es: 1-procurar por ajuda\n 2-ignorar e seguir sua jornada\n 3-mesmo estando em desvantagem e possuir poucas for??as, tentar salvar aquela senhora!" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{

		opcao = 0;

		std::cout << "uma pequena e humilde vila est?? ao seu alcance, voc?? corre para l?? em procura de um guarda" << std::endl;

		std::cout << "ao encontrar um guarda, voc?? explica a ocasi??o e pede por ajuda " << std::endl;
		std::cout << "ambos saem correndo em dire????o ?? idosa e se deparam com uma espantosa cena!!!" << std::endl;
		std::cout << "a idosa que estava sendo espancada, misteriosamente aparece sobre os corpos de todos os seus agressores(aparentemente inconscientes) " << std::endl;
		std::cout << "ao questionar a idosa, ela misteriosamente some e deixa um pacote no ch??o " << std::endl;
		std::cout << "1-abrir  2-guardar em sua mochila" << std::endl;
		std::cin >> opcao;

		if (opcao == 1)
		{
			std::cout << "ao abri-la, voc?? se depara com um misterioso item que te altera de alguma maneira" << std::endl;
			p.energia = p.energia * 1.15;
			std::cout << "voc?? obteve um aumento em sua energia m??xima! " << p.energia << std::endl;
		}
	}

	if (opcao == 2)
	{

		std::cout << "?? uma escolha ego??sta, por??m, segura, sua aventura continua!!!" << std::endl;

	}

	if (opcao == 3)
	{

		opcao = 0;
		while (opcao < 1 || opcao > 2)
		{
			std::cout << "ap??s muito apanhar, sua vit??ria ?? certa, os agressores recuam e deixam a idosa em paz" << std::endl;
			std::cout << "IDOSA:muito obrigada por sua coragem, jovem, sei que ?? algo ego??sta de minha parte, mas...\n poderia me ajudar a carregar meus pertences at?? minha moradia? " << std::endl;
			std::cout << "1-ajuda\n  2-inventa alguma desculpa" << std::endl;
			std::cin >> opcao;
			p.energia = p.energia * 0.20;
		}

		if (opcao == 1)
		{
			std::cout << "a viagem ?? longa e cansativa, sua vit??ria n??o foi barata, consequentemente sua energia est?? escassa\n" << std::endl;
			std::cout << "seu sangramento cessa vagarosamente, voce est?? s?? o p??!\n " << p.energia << "de vida restante" << std::endl;
			std::cout << "quando chega na 'casa' da senhora, percebe que na verdade ?? uma pequena cabana no meio de uma floresta\n" << std::endl;
			std::cout << "ao adentrar seus aposentos, a velha senhore lhe cura com estranhos liquidos(aparentemente algo comestivel)\n" << std::endl;
			std::cout << "seu corpo se cura rapidamente e sente-se com novos poderes\n" << std::endl;
			p.energia = p.energia * 5;
			std::cout << "a idosa se apresenta, seu nome ?? Lucy.\n" << std::endl;
			std::cout << "contando sua hist??ria, ela diz que seu filho era um bravo guerreiro que morrera lutando bravamente contra o rei dem??nio\n" << std::endl;
			std::cout << "como recompensa por sua coragem, voc?? recebe o antigo equipamento de seu falecido filho, assim, podendo lutar, equilibradamente contra inimigos poderosos" << std::endl;
			p.energia = p.energia * 1.8;
			p.forcaFisica = p.forcaFisica * 2.5;
			p.forcaMagica = p.forcaMagica * 0.6;
			std::cout << "com a armadura e espada de um bravo guerreiro seus atributos sobem: " << std::endl;
			std::cout << "sua nova for??a f??sica ?? " << p.forcaFisica << std::endl;
			std::cout << "com potentes defesas, sua vida m??xima ?? elevada " << p.energia << std::endl;

		}
		if (opcao == 2)
		{
			std::cout << "ap??s a luta, sua sobreviv??ncia ?? duvidosa.\n" << std::endl;
			std::cout << "como forma de agradecimento, a senhora retira uma estranha esfera de sua bolsa e diz que ser?? ultil de alguma forma\n" << std::endl;
			std::cout << "sua vida ?? curada completamente e voc?? recebe equipamentos b??sicos de um mago, subindo assim, seus atributos\n" << std::endl;
			std::cout << "IDOSA: meu filho foi um bravo guerreiro outrora, infelizmente nao habita entre n??s, creio que habilidades de um mago, com ataques a longa dist??ncia, seja algo que te ajudar?? a sobreviver!" << std::endl;
			std::cout << "sua for??a m??gica aumenta: " << p.forcaMagica << std::endl;

		}

	}
}

void faseGothamCity(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Voc?? chegou em Gotham City, vamos ver se conseguimos arranjar dinheiro para conseguirmos nos preparar melhor. Quem sabe n??o acabamos encontrando o Batman por aqui!" << std::endl;

		std::cout << "Olhe s??, est??o contratando temporariamente, pode ser uma boa para conseguirmos uma graninha a mais, o que acha?" << std::endl;

		std::cout << "1 - Claro\n2 - Nah, deixa queto" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Contratante: Ol?? cidad??o de gotham city, voc?? est?? atras de uma renda extra certo? Bem, venha comigo, estou precisando de um ajudante, ?? bem rapidinho." << std::endl;
		std::cout << "1 - Vamos la\n2 - To afim n??o, deu pregui??a" << std::endl;

		std::cin >> opcao;

		unsigned int ganho = 0;

		switch (opcao)
		{
			case 1:

				std::cout << "Algum tempo depois..." << std::endl;
				std::cout << "Ufa! Acabamos, obrigado pela ajuda, n??o sei como eu faria isto sozinho, aqui est?? seu pagamento" << std::endl;

				ganho = geraAleatorio() * 100;

				p.creditos = p.creditos + ganho;

				p.energia = p.energia - 5;

				std::cout << "+ $" << ganho << std::endl;

				std::cout << "Conseguimos uma graninha a mais agora, podemos juntas para comprarmos comidas e armas, vamos descan??ar um pouco para recupermos energia ap??s um longo dia de trabalho. E eu juro que vi o Batman em cima de algum predio..." << std::endl;
				break;

			case 2:
				std::cout << "Ah que pena, eu precisava mesmo de ajuda, boa sorte com sua jornada..." << std::endl;
				break;
		}
	}

	if (opcao == 2)
	{
		std::cout << "Ok n??, qualquer coisa pedimos emprestado para alguem." << std::endl;
	}
}

void faseDaFloresta3(struct Personagem &p, struct inimigoFloresta &f)
{
	unsigned int opcao = 0;

	std::cout << "\n\n*********************************xxxxxxxxxxxFLORESTA_DE_NEDERVIERSELxxxxxxxxxx************************************\n" << std::endl;
	std::cout << "Ap??s enfrentar Murilo de Gelo.Nosso heroi se aproxima cada vez mais do seu destino final em sua jornada\n" << std::endl;
	std::cout << "contra o Rei Demonio. Agora que possui a pena da Fenix Glacial em suas maos conseguira matar o Lich que\n" << std::endl;
	std::cout << "habita no lado sombrio da Floresta de Nederviersel. Nosso heroi se depara com uma bifurca????o a sua\n," << std::endl;
	std::cout << "frente e  observa que o caminho a sua direita eh repleto de arvores com aparencia\n" << std::endl;
	std::cout << "decadente que emanam murmurios lamoriosos.Ja o caminho a sua esquerda ?? encoberto por uma nevoa\n" << std::endl;
	std::cout << "espessa e desse local eh possivel ouvir clamores por socorro\n" << std::endl;
	std::cout << "ESCOLHA UM CAMINHO\n" << std::endl;
	std::cout << "\n1-Direita\n2-Esquerda" << std::endl;
	std::cout << "\n*********************************xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*********************************\n" << std::endl;
	std::cin >> opcao;

	if (opcao == 1)
	{
		std::cout << "\n*********************************xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx************************************\n" << std::endl;
		std::cout << "Voce adentrou pela as arvores horripilantes e os murmurios cessaram instaneamente,\n o unico barulho audivel era apenas o de sua respiracao.\n" << std::endl;
		std::cout << "Uma sensa??ao de panico se apossou dele bem como a certeza de que estava sendo observado" << std::endl;
		std::cout << "conforme caminhava.\nApos perambular sem rumo por horas ele nota uma figura concurda proximo a uma caverna\n" << std::endl;
		std::cout << "Conforme vai se aproximando a figura vem tormando forma de uma criatura horripilante" << std::endl;
		std::cout << "Seu cranio era totalmente exposto e de sua testa saiam dois cifres semelhantes ao de um cordeiro\n" << std::endl;
		std::cout << "e estava trajando um manto surrado\nNaquele momento ele teve consciencia que estava diante do temivel Lich" << std::endl;
		std::cout << "\n*********************************xxxxxx UMA BATALHA SE INICIA xxxxxxx**********************************\n" << std::endl;
		std::cout << "\n**************STATUS DO LICH:******************\n" << std::endl;
		mostraStatusDoInimigo(f);

		do
		{
			std::cout << "\n**************ESCOLHA A SUA ACAO******************\n" << std::endl;
			std::cout << "\n1-AtaqueFisico(custa 8 de energia vital)" << std::endl;
			std::cout << "\n2-Ataque Magico(custa 5 de energia vital)" << std::endl;
			std::cout << "\n3-Defender(Sem custos de energia vital)" << std::endl;
			std::cout << "\n**************xxxxxxxxxxxxxxxxxxx*****************\n" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{
				case 1:
					if (f.energia < p.forcaFisica)
					{
						f.energia = 0;

					} else
					{
						f.energia = f.energia - p.forcaFisica;
						p.energia = p.energia - 8;
						if (p.energia < 8)
						{
							p.energia = 0;
							mostraStatusDoJogador(p);
							return;
						}
						std::cout << "**************STATUS_BATALHA******************" << std::endl;
						std::cout << "Vida Linch:" << f.energia << "\nSua Vida atual ??:" << p.energia << std::endl;
						std::cout << "**************xxxxxxxxxxxxxxxxxxx*************" << std::endl;
					}

					break;

				case 2:
					if (f.energia < p.forcaFisica)
					{
						f.energia = 0;
						mostraStatusDoInimigo(f);
					} else
					{
						f.energia = f.energia - p.forcaMagica;
						p.energia = p.energia - 5;
						if (p.energia < 5)
						{
							p.energia = 0;
							mostraStatusDoJogador(p);
							return;
						}
						std::cout << "**************STATUS_BATALHA******************" << std::endl;
						std::cout << "Vida Linch:" << f.energia << "\nSua Vida atual ??:" << p.energia << std::endl;
						std::cout << "**************xxxxxxxxxxxxxxxxxxx*************" << std::endl;
					}
					break;

				case 3:

					if (p.energia < f.forcaFisica)
					{
						p.energia = 0;
						mostraStatusDoJogador(p);
						return;

					} else
					{
						p.energia = p.energia - f.forcaFisica;
						std::cout << "Vida Atual Heroi:" << p.energia << std::endl;
					}
					break;
				default:
					std::cout << "Op????o Invalida" << std::endl;

			}

		} while (f.energia != 0 && p.energia != 0);
		if (f.energia == 0)
		{
			p.creditos = p.creditos + f.creditos;
			p.forcaFisica = p.forcaFisica + 50;
			p.forcaMagica = p.forcaMagica + 250;
			std::cout << "\n**************xxxxxxxxxxxxxxxxxxx******************\n" << std::endl;
			std::cout << "Ap??s derrotar o Lich nosso heroi agora esta em posse de seu poderoso cajado" << std::endl;
			std::cout << "que o possibilatara ressuscitar o druida Stregga que o auxiliara na derrocada contra o Rei Demonio" << std::endl;
			std::cout << "Proxima parada masmorra" << std::endl;
			std::cout << "\n**************xxxxxxxxxxxxxxxxxxx******************\n" << std::endl;
			mostraStatusDoJogador(p);
		}
		return;

	}
	if (opcao == 2)
	{
		std::cout << "\n****************************xxxxxxxxxxxxxxxxxxx******************************\n" << std::endl;
		std::cout << "Voce foi consumido pela nevoa deixando sua visao completamente obstruida" << std::endl;
		std::cout << "O grito se eleva cada vez mais causando confusao mental em nosso heroi" << std::endl;
		std::cout << "Eis que surge de dentro da nevoa uma jovem mulher vestida com uma mortalha" << std::endl;
		std::cout << "Era a deusa da Morte\nNaquele momento ele teve consciencia de seu triste fim" << std::endl;
		p.energia = p.energia - p.energia;
		std::cout << "\n****************************xxxxxxxxxxxxxxxxxxx******************************\n" << std::endl;
	}

}

// TODO ver se tem dona ou dono! Se n??o tiver apago!
void faseDaFloresta(struct Personagem &p)
{

	unsigned int opcao = -1;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Heroi... O rei demonio esta esperando por voce na cidade caida Lore! " << std::endl;
		std::cout << "Antes de poder confronta-lo, voce precisara??? passar pela floresta obscura e derrotar as criaturas malignas que nela habitam.\n\n";

		std::cout << "Voce esta na entrada da floresta, nessa entrada h??? dois estabelecimentos:\n\n1-Centro de treinamento\n2-Magic Shoppe\n3-Nada" << std::endl;
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
				std::cout << "Parab??ns, voc??? adquiriu a Classe Mago, com ela se pode pegar as energias misticas do mundo ao seu redor e enviar fogo e gelo pelo campo de batalha!\n\n" << std::endl;
				p.creditos = p.creditos - 2;

				mostraStatusDoJogador(p);

			} else
			{
				std::cout << "Voc?? n??o possui cr??ditos o suficiente." << std::endl;
			}

		} else if (opcao == 2)
		{

			if (p.creditos >= 1)
			{
				std::cout << "Parab??ns, voc??? adquiriu a Classe Guerreiro, com  ela se pode ter um grande engajamento em combates corpo a corpo!\n\n" << std::endl;
				p.creditos = p.creditos - 2;

				mostraStatusDoJogador(p);

			} else
			{
				std::cout << "Voc?? n??o possui cr??ditos o suficiente." << std::endl;
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

		std::cout << "1-Nada\n2-Poc???es\n3-Armamento" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Po??????o f???sica (Aumenta forca)\n2-Po??????o magia (Aumenta a forca magica)" << std::endl;
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
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 1)
					{
						p.forcaMagica += 10;
						p.creditos -= 1;
					} else
					{
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Holy avenger - Espada m???gica forjada com sangue de deuses, qualquer coisa que estre na frente de seu fio ??? destruido instantaneamente, sem direito a testes de resist???ncia.\n" << std::endl;
				std::cout << "2-super nova bow - Arco que tem a energia de uma estrela concentrada em s???, suas flechas evapora o que toca.\n";
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
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
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
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
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

	std::cout << "\nAp???s uma exaustiva caminhada sobre o sol" << std::endl;
	std::cout << "Voce decide descansar aos pes de uma grande arvore.No meio da noite, um barulho vindo da dire??????o do mato te faz acordar" << std::endl;
	std::cout << "Com o cora??????o acelerado voce avista uma pessoa, na qual esta amea???ando\n" << std::endl;
	std::cout << "O que voce faz?\n1-Batalha\n2-Corre\n3-Conversa\n";
	std::cin >> r;

	if (r == 1)
	{
		std::cout << "Furioso com a situa??????o, voce aceita a batalha!!\n" << std::endl;
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

		std::cout << "Voce escapa daquela situa??????o perigosa.Mas provaste que nao tem coragem suficiente para encarar esse mundo!!!" << std::endl;
		p.energia = p.energia - p.energia;

		return;
	}

	if (r == 3)
	{
		std::cout << "Para ele dialogo n???o ??? uma op??????o!\n";

	}
}

void faseDaCaverna(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Voc??? chegou na floresta e possui duas cavernas. Tem que decidir em qual entrar." << std::endl;
		std::cout << "1-Caverna Verde\n2-Caverna Azul" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Quando voc??? entra possui dois ba???s e precisa escolher apenas uma." << std::endl;

		std::cout << "1-Detona\n2-Fraco\n3-Nenhum Ba???" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Machado voc??? possuir??? maior resistencia\n2-Lan???a voc??? ter??? um ataque potenteroso." << std::endl;
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
						std::cout << "Desculpe mas necessita de mais cr???ditos." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr???ditos." << std::endl;
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
		std::cout << "Quando voc??? entra possui dois ba???s e precisa escolher apenas uma." << std::endl;

		std::cout << "1-Fino Trato\n2-Gostosura\n3-Nenhum Ba???" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Faca voc??? possuir??? maior resistencia\n2-Porrete voc??? ter??? um ataque potenteroso." << std::endl;
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
						std::cout << "Desculpe mas necessita de mais cr???ditos." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr???ditos." << std::endl;
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
	for (unsigned int i = 0; i < direcao.size(); i++)
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
	std::cout << "Voc?? pode escolher essas dire????es\n";
	for (unsigned int i = 0; i < direcao.size(); i++)
	{
		std::cout << direcao[i][0] << " - " << direcao[i] + "\n";
	}
	std::cout << "Qual dire????o voc?? escolhe?\n";
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
							std::cout << "\nVoc?? decidiu seguir em frente! \n\n";
							if (mapa.front() == 'F')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						case 'd':
						case 'D':
							direcao = RemoverOpcao('D', direcao);
							std::cout << "\nVoc?? decidiu virar a direita! \n\n";
							if (mapa.front() == 'D')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						case 'e':
						case 'E':
							direcao = RemoverOpcao('E', direcao);
							std::cout << "\nVoc?? decidiu virar a esquerda! \n\n";
							if (mapa.front() == 'E')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						default:
							std::cout << "Direcao n??o encontrada\n";
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
							std::cout << "\nVoc?? decidiu seguir em frente! \n\n";
							if (mapa.front() == 'F')
							{
								mapa.pop_front();
							}
							break;
						case 'd':
						case 'D':
							direcao = RemoverOpcao('D', direcao);
							std::cout << "\nVoc?? decidiu virar a direita! \n\n";
							if (mapa.front() == 'D')
							{
								mapa.pop_front();
							}
							break;
						case 'e':
						case 'E':
							direcao = RemoverOpcao('E', direcao);
							std::cout << "\nVoc?? decidiu virar a esquerda! \n\n";
							if (mapa.front() == 'E')
							{
								mapa.pop_front();
							}
							break;
						default:
							std::cout << "Direcao n??o encontrada\n";
							ok = true;
							break;
					}
				} while (ok);;
				int op = geraAleatorio() * 5;

				switch (op)
				{
					case 1:
						std::cout << "Voc?? encontrou o fim desse caminho!\n";
						break;
					case 2:
						std::cout << "N??o tem nada aqui!\n\n";
						break;
					case 3:
						std::cout << "Vozes desconhecidas...\n-Esse n??o ?? o seu caminho, volte antes que seja tarde demais!\n\n";
						break;
					case 4:
						std::cout << "Caminho sem sa??da!\n\n";
						break;
					case 5:
						std::cout << "Voc?? andou... e andou... e percebeu que estava andando em c??rculo...\n\n";
						break;
					default:
						std::cout << "Voc?? encontrou o fim desse caminho!\n\n";
						break;
				}

				if (direcao.size() == 0)
				{
					std::cout << "\nVoc?? percebeu que olhou todos os caminhos desse lado, ent??o decidiu que deveria voltar e ir por um caminho diferente! \n\n";
					return false;
				} else
				{
					std::cout << "\nVoc?? voltou para o ??ltimo ponto, antes de se perder, escolha outro caminho!!!\n\n";
				}
			}
			if (mapa.front() == 'X')
			{
				break;
			}
		} while (true);

	}
	return false;
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

	std::cout << "\n\nVoc?? chegou no labirinto do drag??o, aqui vivia o drag??o rei, j?? faz mais de um s??culo que ele morreu, mas at?? hoje a boatos de quem passa por aqui que o seu cora????o ainda pulsa, e quem estiver no dom??nio do cora????o se tornara o mago mais poderoso de todos, talvez mais poderoso que o pr??prio Merlin. \n\nPressione qualquer tecla pra continuar...";
	getchar();
	system("clear||cls");
	std::cout << "Voc?? entrou no labirinto...  \n\n";
	if (escolherDirecao(true, mapa))
	{
		std::cout << "Voc?? finalmente encontrou o cora????o do drag??o! \n";
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
		std::cout << "Diz a lenda, que uma criatura perversa e gigantesca perambula por entre as arvores esguias, se escondendo na densa n??voa causada pelo gelo." << std::endl;
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
		std::cout << "Apos deixar as ferinhas em paz, caminho sem rumo na esperan??a de encontrar o item sagrado." << std::endl;
		std::cout << "Vagueio por horas ate avistar o que poderia ser uma preguica das neves gigante, com vida de " << g.vidaP << " e dano de " << g.dano << " que logo nota minha presen??a e vem em minha direcao." << std::endl;
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
					std::cout << "Ela se aproxima e uma luta come??a pela posse do item sagrado" << std::endl;
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
						std::cout << "Ela se aproxima e uma luta come??a pela posse do item sagrado" << std::endl;
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
					std::cout << "Ela se aproxima e uma luta come??a pela posse do item sagrado" << std::endl;
					std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;
				}
				break;
			case 2:
				std::cout << "Desesperado vendo a pregui??a vindo na minha dire????o, olho para os lados na procura de algum lugar para esconder." << std::endl;
				std::cout << "Quandoa avisto uma arvore antiga oca, decido me esconder" << std::endl;
				std::cout << "Espio pra ver se a preguica que carinhosamente apelidei de Sidnice, como nao avisti ela nas proximidades, saio do tronco e continuo minha viagem." << std::endl;
				std::cout << "Depois de muito tempo, cheguei a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
				std::cout << "Essa luz, A Pena de Fenix de Gelo, bem na minha frente." << std::endl;
				std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
				std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
				std::cout << "Ela se aproxima e uma luta come??a pela posse do item sagrado" << std::endl;
				std::cout << "O inimigo tem " << g.vidaM << " de vida e " << g.danoM << " de dano." << std::endl;
				break;
			case 3:
				std::cout << "Sem saber o que fazer, decido fugir dessa investida correndo na dire????o oposta." << std::endl;
				std::cout << "Depois de muito correr, sem conseguir perder a vista do monstro, por um descuido, n??o vejo um abismo na minha frente e acabo caindo no limbo," << std::endl;
				std::cout << "me perdendo an escurid??o e morrendo na queda." << std::endl;
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
		std::cout << "Eu acho que eles gostaram de mim, mas come??am a correr em uma direcao." << std::endl;
		std::cout << "Sem entender nada, come??o a segui-los incansavelmente atraves da floresta." << std::endl;
		std::cout << "Depois de muito tempo, chegamos a uma clareira com uma nevoa muito espessa, mesmo assim consigo avistar uma luz extremamente forte vindo do centro." << std::endl;
		std::cout << "Essa luz, A Pena de Fenix Glacial, bem na minha frente, nao acredito que os monstrinhos me trouxera ate aqui." << std::endl;
		std::cout << "Me aproximando do objeto, sinto uma presenca muito poderosa se aproximando." << std::endl;
		std::cout << "La da nevoa surge uma imensa criatura branca, que se camufla com a neve, emite sons estranhos e solta uma gosma verde da boca, que parece ser toxico, " << std::endl;
		std::cout << "Murilo de Gelo se aproxima e uma luta come??a pela posse do item sagrado" << std::endl;
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
	int escolha = -1;

	while (escolha < 1 || escolha > 2)
	{
		std::cout << "Voc?? est?? andando pela floresta at?? que se depara com um recrutamento para magos." << std::endl;
		std::cout << "Ent??o voc?? decide emtrar." << std::endl;
		std::cout << "Ao entrar na guilda um poder foi-lhe consedido:" << std::endl;
		p.forcaMagica = p.forcaMagica + 10;
		std::cout << "Agora voc?? tem uma for??a M??gica de " << p.forcaMagica << std::endl;
		std::cout << "Um velho mago lhe da as instru????es: \n1-Voc?? pode fazer miss??es, para ganhar orbites \n2-Ou ent??o voc?? pode fazer miss??es para ganhar intens m??gicos." << std::endl;
		std::cin >> escolha;
	}

	if (escolha == 1)
	{
		std::cout << "Voc?? tem duas miss??es: \n1-ca??ar um javali que esta atormentando a vila (nivel - facil) \n2-buscar o tesouro na torre do Drag??o (nivel - dif??cil)" << std::endl;
		std::cin >> escolha;

		if (escolha == 1)
		{
			std::cout << "Chegando na vila voc?? se depara com o javali." << std::endl;
			std::cout << "1-espantar \n2-matar." << std::endl;
			std::cin >> escolha;

			if (escolha == 1)
			{
				std::cout << "Voc?? espanta o javali e volta para a guilda dos magos." << std::endl;
				p.creditos = p.creditos + 15;

				mostraStatusDoJogador(p);

				faseGuilda(p);
			} else if (escolha == 2)
			{
				std::cout << "Voc?? golpeia o javali mantando-o" << std::endl;
				p.energia = p.energia - 5;
				p.creditos = p.creditos + 24;

				mostraStatusDoJogador(p);
			}
		} else if (escolha == 2)
		{
			std::cout << "Chegando na torre do drag??o voc?? encontra o tesouro com facilidade, mas logo em seguida um tenebroso drag??o aparece! " << std::endl;
			std::cout << "Te dando duas op????es:\n1-Fugir\n2-Lutar" << std::endl;
			std::cin >> escolha;

			if (escolha == 1)
			{
				std::cout << "Voc?? ent??o decidiu fugir? foi um erro!" << std::endl;
				std::cout << "Voc?? infelizmente trope??a e cai pelas escadas da torre e o drag??o ati??a fogo pela boca em sua dire????o. o que voc?? far?? agora?" << std::endl;
				std::cout << "1-usar a magia para tentar se defender\n2-tentar se esquivar." << std::endl;
				std::cin >> escolha;

				switch (escolha)
				{
					case 1:
						if (p.forcaMagica >= 37)
						{
							std::cout << "Voc?? conseguiu se defender e consequentemente fez o drag??o adormecer e conseguiu sair do torre s??o e salvo..." << std::endl;
							std::cout << "Muito bem! Voc?? conseguiu pegar o tesouro!" << std::endl;
							std::cout << "Voc?? volta para a guilda dos magos." << std::endl;
							p.creditos = p.creditos + 41;

							mostraStatusDoJogador(p);
						} else
						{
							std::cout << "Voc?? n??o tem magia o suficiente e ent??o voc?? morre!" << std::endl;
						}
						break;
					case 2:
						std::cout << "Voc?? n??o ?? r??pido o suficiente e ent??o voc?? morre!" << std::endl;
						break;
					default:
						std::cout << "Erro" << std::endl;
						break;
				}
			} else if (escolha == 2)
			{ //lutar com o dragao
				std::cout << "Voc?? escolheu dar o primeiro golpe:\n1-Usar magia para enfrenta-lo\n2-Mudar de ideia e tentar domestica-lo" << std::endl;
				std::cin >> escolha;

				switch (escolha)
				{
					case 1:
						if (p.forcaFisica >= 40 && p.forcaMagica >= 30)
						{
							std::cout << "Voc?? consegue atacar o drag??o e corre para se esconder nos v??o da torre." << std::endl;
							std::cout << "O drag??o desnorteado come??a a atear fogo em toda parte e come??a a vir em sua dire????o.\nO que voc?? far?? agora?" << std::endl;
							std::cout << "1-usar a magia para tentar se defender\n2-tentar se esquivar." << std::endl;
							std::cin >> escolha;

							switch (escolha)
							{
								case 1:
									if (p.forcaMagica >= 37)
									{
										std::cout << "Voc?? conseguiu se defender e consequentemente fez o drag??o adormecer e conseguiu sair do torre s??o e salvo..." << std::endl;
										std::cout << "Muito bem! Voc?? conseguiu pegar o tesouro!" << std::endl;
										std::cout << "Voc?? volta para a guilda dos magos." << std::endl;
										p.creditos = p.creditos + 125;

										mostraStatusDoJogador(p);
									} else
									{
										std::cout << "Voc?? n??o tem magia o suficiente e ent??o voc?? morre!" << std::endl;
									}
									return;
								case 2:
									std::cout << "Voc?? n??o ?? r??pido o suficiente e ent??o voc?? morre!" << std::endl;
									return;
								default:
									std::cout << "Erro" << std::endl;
									return;
							}
						} else
						{
							std::cout << "Voc?? se cansa r??pido e n??o tem for??as o suficiente para enfrenta-lo" << std::endl;
						}
						break;
					case 2:
						std::cout << "Voc?? tenta domestica-lo por??m o drag??o se irrita.\nVoc?? morre!" << std::endl;
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
		std::cout << "Voc?? tem uma miss??o: \nIr at?? o castelo abandonado e pegar a joia do Fim" << std::endl;

		escolha = -1;

		if (escolha == -1)
		{
			std::cout << "No castelo voc?? tem tr??s alternativas\n1-Entrar pela porta da frente\n2-Entrar pelos fundos\n3-Criar sua propia entrada criando um portal" << std::endl;
			std::cin >> escolha;

			switch (escolha)
			{
				case 1:
					std::cout << "Ao entrar pela porta da frente, voc?? cai em uma armadilha e\nVoc?? morre!" << std::endl;
					return;
				case 2:
					std::cout << "Ao entrar pela porta da frente, voc?? se depara com um caminho suspeito e pode ser perigoso!\nFique atento!" << std::endl;
					std::cout << "1-Para desistir\n2-Para continuar" << std::endl;
					std::cin >> escolha;

					if (escolha == 1)
					{
						std::cout << "Voc?? ap??s procurar muito, desiste e vai embora de m??os vazias" << std::endl;
						p.energia = p.energia - 20;

						mostraStatusDoJogador(p);

					} else if (escolha == 2)
					{
						std::cout << "Voc?? se depara com uma porta...mas ela esta emperrada\1-Ignorar\n2-Tentar abrir" << std::endl;
						std::cin >> escolha;
						if (escolha == 1)
						{
							std::cout << "Voc?? ap??s procurar muito, desiste e vai embora de m??os vazias" << std::endl;
							p.energia = p.energia - 20;

							mostraStatusDoJogador(p);
							return;
						} else if (escolha == 2)
						{
							if (p.forcaFisica >= 30)
							{
								std::cout << "Ap??s muito esfor??o a porta se abre e voc?? encontra a joia do fim!" << std::endl;
								std::cout << "Muito bem! Voc?? conseguiu pegar a joia!" << std::endl;
								p.forcaMagica = p.forcaMagica + 16;

								mostraStatusDoJogador(p);
							} else
							{
								std::cout << "Voc?? ap??s procurar muito, desiste e vai embora de m??os vazias" << std::endl;
								p.energia = p.energia - 20;

								mostraStatusDoJogador(p);
							}
						}
					}
					return;
				case 3:
					if (p.forcaMagica >= 37)
					{
						std::cout << "Ap??s muito esfor??o voc?? consegue abrir um portal e na mais pura sorte voc?? encontra a joia do fim!" << std::endl;
						if (p.forcaMagica >= 45)
						{
							std::cout << "Com o portal aberto voc?? conseguiu pegar a joia! e sair com tranquilidade!" << std::endl;
							p.forcaMagica = p.forcaMagica + 16;

							mostraStatusDoJogador(p);
						} else
						{
							std::cout << "Mas, sua magia n??o se estabilizou e o portal fechou, e sua magia n??o ?? suficiente para abrir outro\nTendo somente uma saida: a porta emperrada!" << std::endl;
							if (p.forcaFisica >= 30)
							{
								std::cout << "Ap??s muito esfor??o a porta se abre e voc?? e voc?? consegue sair!" << std::endl;
								std::cout << "Muito bem! Voc?? conseguiu pegar a joia e sair s??o e salvo!" << std::endl;
								p.forcaMagica = p.forcaMagica + 16;

								mostraStatusDoJogador(p);
							} else
							{
								std::cout << "Ap??s horas sem saber o que fazer voc?? e voc?? consegue uzar as suas for??as magicas para usar a joia do fim e se teletransportar para fora do castelo!\n Por??m ao sair, a joia se quebra e voc?? sai de m??os vazias." << std::endl;

								mostraStatusDoJogador(p);
							}
							return;
						}
					} else
					{
						std::cout << "Sua magia n??o ?? suficiente para abrir esta passagem" << std::endl;
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
		std::cout << "Agora tu est??s perambulando pelos campos e montanhas at?? que acidentalmente defronta-se com dois trapaceiros. Tu tens duas op????es: " << std::endl;
		std::cout << "1-Indecis??o\n2-Fujir" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		if (p.armamento == "")
		{
			std::cout << "Voc?? vai na m??o contra os trapaceiros..." << std::endl;
			p.creditos = p.creditos - p.creditos;
			std::cout << "Voc?? foi roubado e agora possui " << "$" << p.creditos << " orbites" << std::endl;

			if (p.creditos <= 5)
			{
				std::cout << "Voc?? sai andando desanimado, e encontra uma mulher pela qual, deixou cair uma joia no ch??o." << std::endl;
				std::cout << "Voc?? tem duas alternativas:" << std::endl;
				std::cout << "1-Devolver para ela\n2-Roubar a joia" << std::endl;
				std::cin >> opcao;

				switch (opcao)
				{
					case 1:
						std::cout << "Voc?? grita para a ela e a devolve a joia." << std::endl;
						std::cout << "Ela muito agradescida lhe-da uma recompensa de $26 orbites" << std::endl;
						p.creditos = p.creditos + 26;

						mostraStatusDoJogador(p);

						std::cout << "Ent??o tu poder?? voltar para a cidade ou continuar vossa jornada..." << std::endl;
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
						std::cout << "Voc?? pega a joia e vai para um com??rcio." << std::endl;
						std::cout << "O vendedor te olha e pergunta: O que tens para mim meu jovem ?" << std::endl;
						std::cout << "Tu mostra para ele a joia e o comerciante te faz duas ofertas:" << std::endl;
						std::cout << "1-Compro esta joia de ti por $30 Orbites\n2-Compro esta joia de ti por uma po????o de For??a M??gica" << std::endl;
						std::cin >> opcao;
						if (opcao == 1)
						{
							p.creditos = p.creditos + 30;

							mostraStatusDoJogador(p);

							std::cout << "Ent??o tu poder?? voltar para a cidade ou continuar vossa jornada..." << std::endl;
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

							std::cout << "Ent??o tu poder?? voltar para a cidade ou continuar vossa jornada..." << std::endl;
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
			std::cout << "Eles n??o se intimidam e partem para cima. Tu tens a oportunidade de mat??-los, o que tu far??s?" << std::endl;
			std::cout << "1-Os Matarei\n2-Os Imobilizarei" << std::endl;
			std::cin >> opcao;

			if (opcao == 2)
			{
				opcao = 0;

				while (opcao < 1 || opcao > 2)
				{
					std::cout << "A partir de qual parte do corpo desejas tu imobilizar os dois trapaceiros?" << std::endl;
					std::cout << "1-A partir da cabe??a\n2-A partir das pernas" << std::endl;
					std::cin >> opcao;

					switch (opcao)
					{
						case 1:
							if (p.forcaFisica >= 30)
							{
								p.energia -= 70;
								p.creditos -= 20;
								std::cout << "Voc?? os imobilizou e continuou a vossa jornada" << std::endl;
							} else
							{
								std::cout << "Desculpe, mas n??o d??..." << std::endl;
							}
							break;
						case 2:
							if (p.forcaFisica >= 15)
							{
								p.energia += 50;
								p.creditos -= 10;
								std::cout << "Voc?? os imobilizou e continuou a vossa jornada" << std::endl;
							} else
							{
								std::cout << "Desculpe, mas n??o d??..." << std::endl;
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
				std::cout << "N??o far??s nada? (...)";
				return;
			}
		}
	}
	if (opcao == 2)
	{
		std::cout << "Voc?? ent??o decidiu fujir? foi um erro!" << std::endl;
		std::cout << "Voc?? infelizmente trope??a e ?? capturado pelos dois trapaceiros. O que far??s agora?" << std::endl;

		std::cout << "1-Pedir reden????o\n2-Escapar\n3-Tentar mat??-los" << std::endl;
		std::cin >> opcao;

		if (opcao == 1)
		{
			std::cout << "Eles nunca lhe dar??o reden????o!" << std::endl;
		} else if (opcao == 3)
		{
			std::cout << "Voc?? sorrateiramente puxa uma faquinha escondida em suas vestes, infelizmente um trapaceiro percebe e te nocauteia" << std::endl;

			if (p.energia >= 60)
			{
				std::cout << "Voc?? perdeu 60 pontos de energia!..." << std::endl;
				p.energia = p.energia - 60;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Voc?? infelizmente morreu!!!" << std::endl;
			}
		} else if (opcao == 2)
		{
			std::cout << "Ao fugir, voc?? chega at?? um desfiladeiro, um local sem saida, escorrega e cai..." << std::endl;
		} else
		{
			std::cout << "N??o far?? nada?" << std::endl;
		}
	}

}

void faseDaMasmorra(struct Personagem &p)
{

	unsigned int opcao = 0;

	std::cout << "Parab??ns, ap??s tanto suor e luta voc?? chegou a masmorra," << std::endl;
	std::cout << "mas achando que a vida ?? um morango? Vai jovem pigmeu escolha um desses 3 caminhos." << std::endl;
	std::cout << "1-Esquerda\n2-Direita\n3-Meio" << std::endl;
	std::cin >> opcao;

	if (opcao == 1)
	{
		std::cout << "Voc???????? est???????? em um tunel e ele est???????? ficando cada vez mais apertado," << std::endl;
		std::cout << "voc???????? precisa abrir uma porta para escapar, mas pra isso vo???????????????? precisa decifrar o enigma:" << std::endl;

		do
		{

			std::cout << "Sempre quando chego trago a tristeza\nMas sempre chego na hora certa\n" << std::endl;
			std::cout << "As vezes venho depois de uma doen????????a\nE outras, depois de um ato de viol????????ncia\n" << std::endl;

			std::cout << "1-Vento\n2-Morte\n3-Arroz" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - 50;

					std::cout << "Sua escolha n????????o foi das mais sabias, volte e tente novamente" << std::endl;

					if (p.energia < 50)
					{
						p.energia = 0;
						return;
					}
					break;

				case 2:
					std::cout << "Parab??ns jovem pigmeu, voc?? passou de fase" << std::endl;

					break;

				case 3:
					p.energia = p.energia - 10;
					std::cout << "Sua escolha n????????o foi das mais sabias, volte e tente novamente" << std::endl;

					if (p.energia < 10)
					{
						p.energia = 0;
						return;
					}
					break;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;

			}

		} while (opcao != 2);

		opcao = 0;

		do
		{

			std::cout << "Vo???????????????? entrou em um labirinto com 3 caminhos, escolha um caminho:" << std::endl;

			std::cout << "1-Caminho escuro\n2-Caminho claro\n3-Caminho barulhento" << std::endl;

			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - p.energia;
					std::cout << "Voc???????? caiu em um po????????o de lava" << std::endl;
					return;

				case 2:
					std::cout << "Boa noiticia, voc?? n??o est?? morto" << std::endl;
					break;

				case 3:
					p.energia = p.energia - 10;
					std::cout << "3:Sua escolha n????????o foi das mais sabias, volte e tente novamente" << std::endl;
					if (p.energia < 10)
					{
						p.energia = 0;
						return;
					}
					break;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;

			}

		} while (opcao != 2);
		opcao = 0;

		do
		{

			std::cout << "Voc???????? est???????? em uma sala com tr????????s alavancas, acione elas na ordem correta para abrir a porta\n" << std::endl;

			std::cout << "1-dica: N????????o sou a ultima, e nem a primeira." << std::endl;
			std::cout << "2-dica: A contagem come????????a por mim" << std::endl;
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
					std::cout << "Olha olha, voc?? est?? me surpreendendo" << std::endl;
					break;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;

			}

		} while (opcao != 3);
		return;
	}

	if (opcao == 2)
	{
		std::cout << "Voc???? est???? em um tunel subaqu????tico e precisa nadar para sobreviver" << std::endl;

		do
		{

			std::cout << "Escolha uma dire????????o, esquerda ou direita" << std::endl;

			std::cout << "1-Esquerda\n2-Direita" << std::endl;
			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - 25;
					std::cout << "Voc???? encontrou uma criatura aqu????tica mitol????gica" << std::endl;

					if (p.energia < 25)
					{
						p.energia = 0;
						return;
					}
					break;

				case 2:

					std::cout << "Ap????s nadar muito voc???? consegue sair com vida, agora siga a sua jornada" << std::endl;

					break;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;
			}

		}

		while (opcao != 2);

		opcao = 0;

		do
		{

			std::cout << "Voc???? acabou sendo envenenado durante a sua ultima jornada, mas tenho uma boa noiticia,\n" << std::endl;
			std::cout << "Na sua frente tem dois potes, por????m s???? um deles ???? o antidoto pra o veneno.Escolha um pote:" << std::endl;

			std::cout << "1- O grande\n2- O pequeno" << std::endl;

			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - p.energia;
					std::cout << "Ops pote errado, ???? apenas ????gua, voc???? n????o resistiu" << std::endl;
					return;

				case 2:
					std::cout << "Boa escolha pequeno gafanhoto, o veneno n????o est???? mais em seu corpo,\n" << std::endl;
					std::cout << "agora voc???? pode seguir seu caminho" << std::endl;
					break;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;

			}

		} while (opcao != 2);
		opcao = 0;

		do
		{

			std::cout << "Voc???? encontrou uma bruxa que est???? disposta a te ajudar com a sua jornada,\n" << std::endl;
			std::cout << "Deseja aceitar a sua ajuda?\n" << std::endl;

			std::cout << "1-Sim" << std::endl;
			std::cout << "2-N????o" << std::endl;

			std::cin >> opcao;

			switch (opcao)
			{

				case 1:
					p.energia = p.energia - p.energia;
					std::cout << "Voc???? n????o deu ouvidos a sua m????e quando ela disse que bruxas n????o s????o confiav????s,\n" << std::endl;
					std::cout << "Agora ela te jogou em feiti????o" << std::endl;
					return;

				case 2:
					p.energia = p.energia - p.energia;
					std::cout << "Voc???? resolveu lembrar de sua m????e e n????o deu ouvidos a bruxa, por????m era tarde de mais,\n" << std::endl;
					std::cout << "Voc???? est???? preso em uma areia movedi????a" << std::endl;
					return;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;

			}

		} while (opcao != 4);

		return;
	}

	if (opcao == 3)
	{
		std::cout << "Voc???? est???? em um sal????o escuro com dois caminhos, escolha um deles:" << std::endl;

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
					std::cout << "N????o foi uma boa escolha, espinhos afiados sairam da parede e fizeram de voc???? uma penera" << std::endl;
					p.energia = p.energia - p.energia;
					return;

				default:
					std::cout << "Op????????????????o invalida" << std::endl;
			}

		}

		while (opcao != 1);
	}

	opcao = 0;

	do
	{

		std::cout << "Voc?? est?? em frente a uma porta, mas derepente come??a subir uma fuma??a t??xica,\n" << std::endl;
		std::cout << "Voc?? precisa escolher entre voltar, ou tentar achar uma saida" << std::endl;

		std::cout << "1- Voltar:\n2- Achar outra saida" << std::endl;

		std::cin >> opcao;

		switch (opcao)
		{

			case 1:
				p.energia = p.energia - p.energia;
				std::cout << "N??o foi uma boa escolha, o caminho estava fechado" << std::endl;
				return;

			case 2:
				std::cout << "Voc?? foi corajoso e achou uma pequena fresta na parede e conseguiu escapar" << std::endl;
				break;

			default:
				std::cout << "Op????????????????o invalida" << std::endl;

		}

	} while (opcao != 2);
	opcao = 0;

	do
	{

		std::cout << "Voc?? acaba encuralado por um esqueleto com uma espada encantada e precisa batalhar com ele,\n" << std::endl;
		std::cout << "Escolha sua arma:" << std::endl;

		std::cout << "1-Graveto" << std::endl;
		std::cout << "2-Espada" << std::endl;

		std::cin >> opcao;

		switch (opcao)
		{

			case 1:
				p.energia = p.energia - p.energia;
				std::cout << "?? serio que voc?? fez essa escolha jovem gafanhoto? Nem preciso falar que voc?? morreu n??h" << std::endl;

				return;

			case 2:
				p.energia = p.energia - p.energia;
				std::cout << "Boa escolha, por??m ap??s tantos obst??culos voc?? est?? muito fraco para batalhar e" << std::endl;

				return;

			default:
				std::cout << "Op????????????????o invalida" << std::endl;

		}

	} while (opcao != 3);
	std::cout << "Narra????????o blabla" << std::endl;
	p.energia = p.energia - p.energia;
	return;
}

void faseDaDungeon(struct Personagem &p)
{
	//Escolha das miss??es
	int resposta = 0;
	int repetir;
	unsigned int escolha = 0;

	while (escolha < 1 || escolha > 2)
	{
		std::cout << "Depois de sair Voc?? v?? um quadro de miss??es, nele s?? tem 2 papeis. Deseja olhar eles? \n";
		std::cout << "1-Sim\n2-N??o";
		std::cin >> escolha;
	}

	if (escolha == 1)
	{
		for (;;)
		{
			std::cout << "Digite 1-MISS??O DE ALTO NIVEL\n 2-MISS??O BAIXO NIVEL";

			std::cin >> escolha;
			std::cout << "--------------------------------";

			if (escolha == 1)
			{
				std::cout << "MISS??O DE ALTO NIVEL!!!" << std::endl;
				std::cout << "RECOMPENSA DE 200 CR??DITOS" << std::endl;
				std::cout << "Objetivo:Matar todos os Esqueletos!" << std::endl;
				std::cout << "Existe uma Dungeon dos Esqueletos de Schr??dinger que precisa ser destruida antes que sej?? tarde, eles s??o muito fortes ent??o tomem cuidado ao tentar destruir o lugar\n" << std::endl;
				std::cout << "Se desejar ir basta seguir pelo caminho das ??rvores Mortas que est?? ao lado da entrada para a cidade.\n" << std::endl;
			} else if (escolha == 2)
			{
				std::cout << "MISS??O DE BAIXO NIVEL -_-" << std::endl;
				std::cout << "RECOMPENSA DE 70 CR??DITOS" << std::endl;
				std::cout << "Objetivo:Destruir todos os Slimes!" << std::endl;
				std::cout << "Perto da cidade existem um campo aberto onde varios Slimes est??o vivendo, eles n??o fazem mal a ningu??m, mas est??o sujando e assustando alguns moradores da cidade\n" << std::endl;
				std::cout << "Eles s??o bem fraquinhos ent??o s??o bem faceis de serem derrotados\n" << std::endl;
				std::cout << "Caso aceite o caminho para o lugar ?? logo depois da saida da cidade.\n " << std::endl;
			}
			repetir = 0;
			std::cout << "Se voc?? desejar ler a outra miss??o digite 1 se n??o digite 2 para escolher uma delas" << std::endl;
			std::cin >> repetir;

			if (repetir == 2)
			{
				break;
			}
		}
		escolha = 0;

		std::cout << "Agora precisa decidir qual delas voc?? escolhe?\n 1-Miss??o de Alto nivel\n 2-Miss??o de baixo nivel" << std::endl;
		std::cin >> escolha;

		if (escolha == 1)
		{
			escolha = 0;
			std::cout << "ok ent??o voc?? realmente ?? ganancioso hehe\n" << std::endl;
			std::cout << "Ent??o voc?? volta para o come??o da cidade e desce o caminho das ??rvores Mortas e vai percebendo que o ambiente est?? ficando estranho e cinza\n" << std::endl;
			std::cout << "Depois de um bom tempo andando voc?? chega em uma dungeon bem grande e voc?? v?? uma porta\n deseja bater?" << std::endl;
			std::cout << "1 - sim 2 - n??o" << std::endl;
			std::cin >> escolha;
			if (escolha == 1)
			{
				std::cout << "Voc?? vai chegando perto e o clima fica cada vez mais tenso\n" << std::endl;
				std::cout << "Voc?? bate..." << std::endl;
				std::cout << "..." << std::endl;
				escolha = 0;
				std::cout << " POW POW os esqueletos derrubam a porta e v??o para cima de voc??" << std::endl;
				std::cout << "1 - correr\n 2- lutar?\n" << std::endl;
				std::cin >> escolha;
				switch (escolha)
				{
					case 1:
						std::cout << "Voc?? vira e tenta correr, por??m uma flecha te acerta bem no peito." << std::endl;
						std::cout << "Voc?? morreu de hemorragia kkkk" << std::endl;
						std::cout << "Tente novamente!!" << std::endl;
						return;
					case 2:
						std::cout << "Lutar? kkkkk como que luta sem espada?" << std::endl;
						std::cout << "Os esqueletos te cercam e enfiam as espadas em voc??" << std::endl;
						std::cout << "Voc?? morreu kkkkk -_-" << std::endl;
						std::cout << "Tente novamente!!" << std::endl;
						return;

					default:
						std::cout << "Voc?? fica parado e eles te cercam e te matam a espadadas" << std::endl;
						std::cout << "Voc?? morreu kkkkkkkk -_-" << std::endl;

						return;
				}
			}
			if (escolha == 2)
			{
				escolha = 0;
				std::cout << "De dentro da porta voc?? ouve uma voz" << std::endl;
				std::cout << "Responda uma pergunta, acertando poder?? entrar errando morrer??. " << std::endl;
				std::cout << "Voc?? reposnde? 1-sim 2-n??o";
				std::cin >> escolha;
				if (escolha == 1)
				{
					std::cout << "A pergunta ?? com quantos paus se fazem uma canoa?" << std::endl;
					std::cout << "1- Um s??\n 2-300\n 3-N??o sei nunca fiz uma canoa" << std::endl;
					std::cin >> resposta;
					switch (resposta)
					{
						case 1:
							std::cout << "Errado\n voc?? recebe um flechada e morre" << std::endl;
							return;
						case 2:
							std::cout << "Errado\n voc?? recebe 2 flechas no peito e morre" << std::endl;
							return;
						case 3:
							std::cout << "Bom como voc?? acertou te deixarei entrar, MAS ?? por sua conta e risco" << std::endl;
							break;

						default:
							std::cout << "falou errado perdeu a vez" << std::endl;
							return;
					}
				}
				escolha = 0;
				std::cout << "Agora a porta est?? aberta em sua frente deseja entrar?\n 1-sim 2-n??o" << std::endl;
				std::cin >> escolha;
				if (escolha == 1)
				{
					std::cout << "Voce entrou dentro na dungeon" << std::endl;
					std::cout << "?? um sal??o grande e escuro, aporta se fechou atr??s de voc??, n??o tem como escapar" << std::endl;
					std::cout << "Voc?? da mais alguns passos e POW POW POW de novo,\n esqueletos por toda a parte est??o saindo n??o ah o que ser feito" << std::endl;
					std::cout << "Voc?? morreu -_- " << std::endl;
					return;

				} else if (escolha == 2)
				{
					std::cout << "voc?? fica parado quando derrepente toma 3 flechadas de alguns esqueletos que estavam andando pelo lugar" << std::endl;
					return;

				}
				if (escolha == 2)
				{
					std::cout << "J?? que voc?? n??o quer responder come??a o game de novo ai" << std::endl;
					return;
					//p.energia = p.energia - p.energia;
				}
			}

		}
		if (escolha == 2)
		{
			std::cout << "Voc?? vai ao final da cidade e anda um pouco por uma estrada,\n o ambiente ?? bem agradavel." << std::endl;
			std::cout << "andando mais um pouco voc?? encontra um campo bem aberto, onde voc?? acha os Slimes que as pessoas tanto desgostam" << std::endl;
			std::cout << "Eles parecem muito amigaveis voc?? realmente deseja exterminar todos eles\n aparentemente s?? de chegar perto com a m??o levantanda para bater eles j?? se assustam" << std::endl;
			std::cout << "Tente espantalos com gritos e movimentos brucos" << std::endl;
			std::cout << "1- gritar e correr atr??s deles 2-n??o fazer nada 3 - socar " << std::endl;
			escolha = 0;
			std::cin >> escolha;
			switch (escolha)
			{
				case 1:
					std::cout << "Voc?? grita e corre na dire????o deles, as pessoas que estavam perto te veem gritando e correndo." << std::endl;
					std::cout << "Os Slimes correm de medo de voc?? e v??o para o meio da floresta e provavelmente v??o demorar muito tempo para voltar" << std::endl;
					std::cout << "Voc?? volta para a cidade e ganha seu dinheiro" << std::endl;
					p.creditos = p.creditos + 70;
					mostraStatusDoJogador(p);
					std::cout << "Obrigado por jogar XD" << std::endl;

					return;
				case 2:
					std::cout << "... o que voc?? queria que acontecesse??" << std::endl;
					return;

				case 3:
					std::cout << "Voc?? anda para o Slime mais proximo e da um SOCASSO na cara dele,\n ele sai rolando e fica muito triste e vai embora, os outros o acompanham" << std::endl;
					std::cout << "Voc?? volta para a cidade e ganha seu dinheiro" << std::endl;
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
		std::cout << "Precisa ler as miss??es se n??o voc?? n??o joga boa sorte e tente novamente." << std::endl;

	}
}

void faseDaMontanha(struct Personagem &p, struct Inimigo &i)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{

		std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "**Narrador-- Agora que j?? nos equipamos, suportaremos os perigos contidos nas montanhas congeladas.\n" << std::endl;
		std::cout << "Cuja a lenda menciona a exist??ncia de um mago que habita o local. Se esta estiver correta\n" << std::endl;
		std::cout << "conseguiremos usufruir de sua sabedoria mistica que sera util em nossa jornada.\n" << std::endl;
		std::cout << " **Narrador--'Durante a escalada o heroi ?? atingido por uma nevasca.Com o objetivo\n" << std::endl;
		std::cout << " de se proteger decide se abrigar numa caverna, mal sabe ele dos segredos que o aguardam l?? dentro.\n" << std::endl;
		std::cout << "Ent??o cuidadosamente se esgueira pela pequena abertura.Para sua surpresa deparou-se\n" << std::endl;
		std::cout << " com um anci??o dormindo sob um altar." << std::endl;
		std::cout << " O que devo fazer?\n" << std::endl;
		std::cout << "1-Ataca-lo enquanto dorme.\n2-Acorda-lo pacificamente." << std::endl;
		std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "\n" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "\n**Heroi-- Empunho a minha arma e decido desferir um golpe em seu peito,\n" << std::endl;
		std::cout << "porem a lamina encosta de relance.Inesperadamente sou lancado contra uma parede\n" << std::endl;
		std::cout << "para o meu desespero o mago despertou antes que conseguisse mata-lo.\n" << std::endl;
		std::cout << "Me dou conta que uma jaula surge ao meu redor me prendendo.\n" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
		p.vida = p.vida - i.Pdano;
		if (p.vida < i.Pdano)
		{
			p.vida = 0;
			return;
		}

		std::cout << "\n**Narrador-- O impacto lhe causou dano, voce possui: " << p.vida << " de vida atual\n" << std::endl;
		std::cout << "Escuto uma voz fria como gelo me indagando--'Como me encontrou?'\n" << std::endl;
		std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
		std::cout << "O que devo responder?\n" << std::endl;
		std::cout << "1-**Heroi-- N??o te interessa.\n" << std::endl;
		std::cout << "2-**Heroi-- Vim em busca de um abrigo para achar voce apos a nevasca, mas agora que ja estou aqui, vim mata-lo atras do artefato mistico, que me protejer?? do frio da floresta g??lida.\n" << std::endl;
		std::cout << "3-**Heroi-- Vim em busca de um abrigo para achar voce apos a nevasca," << std::endl;
		std::cout << "mas agora que ja estou aqui, vim atras de voc?? perdedor, que est?? se escondendo do Rei D??monio.\n " << std::endl;
		std::cin >> opcao;

		switch (opcao)
		{
			case 1:
				std::cout << "\nTolo agora voce esta fadado a passar a resto da vida nessa jaula\n" << std::endl;
				std::cout << "MUAHAHAHAHA\n" << std::endl;
				return;

			case 2:
				std::cout << "Mas ent??o voc?? jovem guerreiro deveria ter ao menos pedido para mim, pois tem um garoto\n" << std::endl;
				std::cout << "no qual estou esperando cujo foi escolhido para nos salvar do Rei Dem??nio e a proposito qual seria seu nome?Ent??o o heroi responde: Eu sou o escolhido.\n" << std::endl;
				std::cout << "Aaaaa ent??o voc?? ?? o escolhido, ao inv??s de ter me atacado deveria ter conversado comigo,\n" << std::endl;

				break;
			case 3:
				std::cout << " Mago-- Perdedor? O Rei D??monio ele tem uma unica fraqueza,\n" << std::endl;
				std::cout << "que seria se o t??o falado escolhido o enfrentasse, mas aproposito qual seria seu nome?\n" << std::endl;
				std::cout << "Heroi-- Eu sou o escolhido e vim atras do artefato mistico.\n" << std::endl;

				break;

			default:
				std::cout << "Opcao Invalida" << std::endl;
		}

	}

	if (opcao == 2)
	{

		std::cout << "\nHeroi-- Entao balanco seus ombros suavemente tomando cuidado para n??o assusta-lo\n" << std::endl;
		std::cout << "Sou atingido por um raio na regiao do peito que veio das m??os do anci??o" << std::endl;
		p.vida = p.vida - i.Gdano;
		std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;

		if (p.vida <= 30)
		{
			std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
			std::cout << "\nSua vida atual ??: " << p.vida << "\n" << std::endl;
			std::cout << "O dano sofrido te enfraqueceu.\n" << std::endl;
			std::cout << "ent??o oque deseja fazer??\n1-Contra atacar. \n2-N??o fazer nada. " << std::endl;
			std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
			std::cin >> opcao;
		}
		if (p.vida > 30)
		{
			std::cout << "Narrador-- Nossa que sorte foi que a magia que ele usou n??o pegou em cheio\n" << std::endl;
			std::cout << "Voce est?? com " << p.vida << " de vida.\n" << std::endl;
			std::cout << "Agora o que deseja fazer?" << std::endl;
			std::cout << "\n1-Contra atacar. \n2-N??o fazer nada." << std::endl;
			std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
			std::cin >> opcao;
		}

		switch (opcao)
		{

			case 1:

				i.vida = i.vida - p.forcaFisica;

				if (i.vida > 50)
				{
					std::cout << "\n**Narrador-- Vida atual do inimigo: " << i.vida << "\n" << std::endl;
					std::cout << "Voce causou pouco dano e deixou sua defesa vulneravel:\n" << std::endl;
					p.vida = p.vida - p.vida;
				}
				if (i.vida <= 50)
				{
					std::cout << "\n**Narrador-- Vida atual do inimigo: " << i.vida << "\n" << std::endl;
					std::cout << "Voce causou bastante dano, mas deixou sua defesa vulneravel:\n" << std::endl;
					p.vida = p.vida - p.vida;
				}

				return;

			case 2:

				std::cout << "\n**Narrador-- Ent??o o mago aparece ao seu lado e lhe diz: Oque faz aqui jovem guerreiro ?\n" << std::endl;
				std::cout << "**Her??i-- responde a ele: vim em busca do artefato mistico para que ele possa atravessar as florestas g??lidas.\n" << std::endl;
				break;

			default:

				return;
		}
	}
	std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "\n**Mago-- Ent??o para que voc?? prove que ?? o escolhido me responda a seguinte pergunta:\n" << std::endl;
	std::cout << "O que o livro faz?\n" << std::endl;
	std::cout << "1-Eu sei.\n2-N??o fa??o ideia.\n" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
	std::cin >> opcao;

	if (opcao == 1)
	{
		std::cout << "Heroi--O livro me ajudara a passar pelas florestas g??lidas e\n" << std::endl;
		std::cout << "que com ele conseguirei unir todos os itens miticos para derrotar o Rei Demonio.\n" << std::endl;
		std::cout << "Mago-- Impostor o verdadeiro guerreiro n??o saberia que com ele voce podera unir os itens miticos." << std::endl;

	}

	if (opcao == 2)
	{
		std::cout << "**Heroi-- Eu n??o mas a unica coisa que me falaram foi que eu precisaria dele para que eu passe pelas Florestas G??lidas." << std::endl;
		std::cout << "\n**Narrador-- Ent??o ele percebendo que voc?? ?? o salvador, pede perd??o a voce pelos danos causados e que se voce sair desse " << std::endl;
		std::cout << "jeito ira morrer l?? fora ent??o ele te d?? uma sopa na qual ele diz que ela ira te curar em +40 de vida e tamb??m ira melhorar um pouco suas habilidades magicas em +15." << std::endl;

		std::cout << "Voce estava com " << p.vida << " de vida\n" << std::endl;
		std::cout << "e com " << p.vida << " de habilidades Magicas.\n" << std::endl;
		p.vida = p.vida + 40;
		p.habilidadesMagicas = p.habilidadesMagicas + 15;

		std::cout << "Agora voce est?? com " << p.vida << " de vida.\n" << std::endl;
		std::cout << "e com " << p.habilidadesMagicas << " de habilidades Magicas.\n" << std::endl;
	}

	std::cout << "\n**Narrador-- Ele te explica, que o livro te ajudar?? a passar pelas Florestas G??lidas,\n" << std::endl;
	std::cout << "pois quem transporta o livro ira usufruir de uma magia onde te protejer?? de frios extremos.\n" << std::endl;

	std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;

	std::cout << "\n**Heroi-- Agora irei seguir minha miss??o de passar pelas florestas g??lidas.\n" << std::endl;
	std::cout << "\n**Narrador-- Ent??o o heroi se despede do mago sai da caverna em meio a nevasca e segue sua miss??o.\n" << std::endl;
	std::cout << "\n------------------------------------------------------------------------------------------\n" << std::endl;
}

void faseDoLivro(struct Personagem &p)
{ //minha fase

	unsigned int opcao = 0;

	std::cout << "Voc?? passou pela cidade, mas, ainda n??o concluiu; ";
	std::cout << "Precisa coletar mais equimentos, para lutar com o rei Dem??nio, ";
	std::cout << "se quiser ter uma chance, escolha com cuidado qual caminho ir?? seguir!" << "\n";

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Ent??o, qual deseja escolher?" << "\n" << std::endl;
		std::cout << "1 - Livraria\n2 - Zona do desejo\n" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "O vendedor te olha e pergunta: Qual sabedoria precisa para hoje?" << std::endl;

		std::cout << "1 - Nada\n2 - Como vencer em uma batalha\n3 - Ah, sei l??\n" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1 - Livro com estrat??gias de guerra (D?? muita energia)\n2 - Um l??pis (D?? pouca energia)\n" << std::endl;
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
						std::cout << "Desculpe mas n??o posso dar-lhe o que deseja." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas n??o posso te vender isso no momento." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Melhor se preparar pra morte!" << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "Gente, se acalma a??....";
		}

	}

	if (opcao == 2)
	{
		std::cout << "O vendedor te olha e pergunta: Pronto para guerrear e vencer com seu poder?" << std::endl;

		std::cout << "1 - Acho que n??o\n2 - Um drag??o\n3 - Um ford de prote????o\n" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			std::cout << "Agora sim, mostre a eles que voc?? n??o ser?? pego facilmente!" << std::endl;

			if (p.creditos >= 200)
			{
				std::cout << "Muitos morrerram para terem sua sabedoria!" << std::endl;
				p.creditos = p.creditos - 200;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Arrasaaa! D?? um show de precis??o e coragem!" << std::endl;
			}

		} else if (opcao == 3)
		{
			std::cout << "?? agora ningu??m me mata" << std::endl;

			if (p.creditos >= 25)
			{
				std::cout << "Talvez..." << std::endl;
				p.creditos = p.creditos - 25;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Voc?? n??o merece estar aqui, saia!!!!" << std::endl;
			}
		} else
		{
			std::cout << "Sa??a daqui agora!" << std::endl;
		}
	}
}

void naomateobrendon(struct Personagem &p)
{

	unsigned int opcao = 0, opcao2 = 0;

	std::cout << "Derrepente voc?? ?? jogado em um parque, e ao seu lado sentado est?? um dos escravos do mal gosto e assassino de bom humor...BRENDON!!!" << std::endl;
	std::cout << "Voc?? deve atura-lo sem matar, caso n??o consiga concluir a tarefa voc?? ser?? recompensado como merece estamos entendidos?" << std::endl;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Voc?? tem algumas op????es como: 1-Mata-lo assim que avista-lo para previnir caso seja algum inimigo (recomendado)." << "\n" << "2-Pedir informa????o do local onde se encontra." << "\n" << std::endl;
		std::cin >> opcao;
	}

	if (opcao == 1)
	{

		p.vidaDoBrendon = p.vidaDoBrendon - p.vidaDoBrendon;

		std::cout << "-Sua escolha matou Brendon (boa escolha!)." << std::endl;

	}

	if (opcao == 2)
	{
		std::cout << "Voce decide pedir informa????o.\n" << std::endl;
		std::cout << "P-psss Hey, como vai cara?" << std::endl;
		std::cout << "P-Perd??o qual seu nome?\n" << std::endl;
		std::cout << "B-Haha, que sigilo ?? esse? prazer eu sou Brendon como vai voc???...EI VOC?? QUER OUVIR UMA PIADA? HAHAH.\n" << std::endl;
		std::cout << "P-Err...Ah...claro, porqu?? n??o?" << "\n" << std::endl;
		std::cout << "B-O que a vaca disso pro boi? MUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n" << "Gostou? Minhas piadas s??o as melhores por aqui onde moro!" << "\n" << std::endl;

		while (opcao2 < 1 || opcao2 > 2)
		{

			std::cout << "-Eu sei depois dessa voc?? quer matar ele n??? Ta a??.\n" << "1-E voc?? ser?? feliz.\n" << std::endl;
			std::cout << "2-Se quiser prosseguir. \n " << std::endl;
			std::cin >> opcao2;
		}

		switch (opcao2)
		{
			case 1:
				if (opcao2 == 1)
				{
					p.vidaDoBrendon = p.vidaDoBrendon - p.vidaDoBrendon;
					std::cout << "Sua escolha matou Brendon (boa escolha!)." << std::endl;
				}
				break;

			case 2:
				if (opcao2 == 2)
				{
					std::cout << "-Queria ter a sua paci??ncia" << std::endl;
					std::cout << "P-Ah ??? quem mais mora aqui?questiona" << "\n" << std::endl;
					std::cout << "B-Ah..S?? eu mesmo rindo" << "\n" << "P-Ta explicado..." << std::endl;
					break;
				}
		}
	}

}

void faseDaCidade2(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Voc?? est?? na rua principal da cidade, nesta rua voc?? v?? dois estabelecimentos: Uma quitanda de um lado uma loja de armas do outro.\n Para onde voc?? deseja ir?" << std::endl;
		std::cout << "1-mercadinho\n2-Loja de armaduras" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;

		std::cout << "1-Nada\n2-Comida\n3-a vitoria" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-feij??o (D?? muita energia)\n2-espinafre (D?? pouca energia)" << std::endl;
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
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas n??o posso te vender isso..." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Prepare-se para perder idiota!!!" << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "Que cara estranho....";
		}

	}

	if (opcao == 2)
	{
		std::cout << "O vendedor te olha e pergunta: Pronto pra batalha?" << std::endl;

		std::cout << "1-N??o\n2-Espada\n3-Martelo" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			std::cout << "Bela escolha!" << std::endl;

			if (p.creditos >= 200)
			{
				std::cout << "Muitos cair??o por essa l??mina!!" << std::endl;
				p.creditos = p.creditos - 200;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Pena voc?? n??o merece este tesouro plebeu!!" << std::endl;
			}

		} else if (opcao == 3)
		{
			std::cout << "Pelo menos d?? para fazer se defender kkk" << std::endl;

			if (p.creditos >= 25)
			{
				std::cout << "ok..." << std::endl;
				p.creditos = p.creditos - 25;

				mostraStatusDoJogador(p);
			} else
			{
				std::cout << "Saia daqui farrapo!!!" << std::endl;
			}
		} else
		{
			std::cout << "V?? embora!." << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	std::srand(std::time(nullptr));

	struct Personagem j = boasVindasDoJogo();
	struct InimigosGelidos g = faseFlorestaGelida();
	struct inimigoFloresta f = faseDaFloresta();

	std::cout << "Voc?? recebeu um presente das divindades da terra!\n";
	std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Cidade" << std::endl;
	faseDaCidade(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Labirinto" << std::endl;
	faseLabirinto(j);

	if (j.forcaMagica == 60)
	{
		mostraStatusDoJogador(j);
		std::cout << std::endl << "Caverna" << std::endl;
		faseDaCaverna(j);

		mostraStatusDoJogador(j);
		std::cout << std::endl << "Floresta" << std::endl;
		faseDaFloresta(j);

		mostraStatusDoJogador(j);
		std::cout << std::endl << "Floresta II" << std::endl;
		faseDaFloresta2(j);
	} else
	{

		mostraStatusDoJogador(j);
		std::cout << std::endl << "Batalha" << std::endl;
		faseBatalha(j);

		mostraStatusDoJogador(j);
		std::cout << std::endl << "Gothan City" << std::endl;
		faseGothamCity(j);

		mostraStatusDoJogador(j);
		std::cout << std::endl << "A velha" << std::endl;
		faseDaVeinha(j);
	}

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Floresta g??lida" << std::endl;
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
	std::cout << std::endl << "O livro" << std::endl;
	faseDoLivro(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Cidade II" << std::endl;
	faseDaCidade2(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Fase da floresta III" << std::endl;
	faseDaFloresta3(j, f);

	mostraStatusDoJogador(j);
}

