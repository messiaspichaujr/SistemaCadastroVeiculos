#include <iostream>
#include <string>
#include <vector>
#include <conio2.h>
#include <windows.h>
#include <clocale>

using namespace std;

void limparArea(int colIni, int linIni, int colFin, int linFin)
{
	for (int x=colIni; x<=colFin; x++)
	{
		for (int y=linIni; y<=linFin; y++)
		{
			gotoxy(x,y); cout << " ";
		}
	}
}


void desenharMoldura(int colIni, int linIni, int colFin, int linFin)
{
	// limpa a área da moldura
	limparArea(colIni, linIni, colFin, linFin);
	
	// desenha as linhas horizontais
	for(int x=colIni; x<=colFin; x++)
	{
		gotoxy(x,linIni); 
		cout << "-";
		gotoxy(x,linFin); 
		cout << "-";
		
	}
	
	// desenha as linhas verticais
	for(int y=linIni; y<=linFin; y++)
	{
		gotoxy(colIni,y);
		cout << "|";
		gotoxy(colFin,y);
		cout << "|";
	}
	
	// arruma os cantos
	gotoxy(colIni,linIni); cout << "+";
	gotoxy(colFin,linIni); cout << "+";
	gotoxy(colIni,linFin); cout << "+";
	gotoxy(colFin,linFin); cout << "+";
}



void centralizar(string msg, int lin, int colIni, int colFin)
{
	int meio;
	meio = (colFin-colIni-msg.length())/2;
	gotoxy(meio,lin);
	cout << msg;
}


//GRUPO MESSIAS,WILLIAM,NATHALIA (Caso alguem copie)
string mostrarMenu(int col, int lin, vector<string> opcoes)
{
	string op;
	int x;
	int colFin = col + opcoes[0].size() + 1;
	int linFin = lin + opcoes.size() + 3;
	
	desenharMoldura(col, lin, colFin, linFin);
	centralizar("Menu", lin+1, col, colFin);
	col ++;
	lin += 2;
	for (x=0; x<opcoes.size(); x++)
	{
		gotoxy(col, lin+x); cout << opcoes[x];
	}
	gotoxy(col, lin+x);
	cout << "Opcao : ";
	op = getche();
	
	return op;
}

string perguntar(int col, int lin, string pergunta)
{
	string resp;
	gotoxy(col,lin);
	cout << pergunta;
	resp = getche();
	resp = toupper(resp[0]);
	limparArea(col,lin,col+pergunta.size()+3,lin);
	return resp;
}


//*****************************************************************************************************************************//
//*****************************************************************************************************************************//



struct Veiculo {
  string placa;
  string categoria;
  string marca;
  string modelo;
  int ano_fabricacao;
  string cor;
  string responsavel_legal;
};

vector<Veiculo> listaCarros;

void cadastroVEICULO()
{
	bool achei;
	int posicao;
	string resp;
	Veiculo registro;
	
	desenharMoldura(9, 4, 70, 15);
        centralizar("Cadastro de Carros", 6, 10, 70);
        gotoxy(11,7); cout << "Placa: ";
        gotoxy(11,8); cout << "Categoria: ";
	gotoxy(11,9); cout << "marca: ";
	gotoxy(11,10); cout << "modelo: ";
        gotoxy(11,11); cout << "ano_fabricacao: ";
	gotoxy(11,12); cout << "cor: ";
	gotoxy(11,13); cout << "responsavel_legal: ";
    
    // pergunta o codigo do carro
    gotoxy(20,7); getline(cin, registro.placa);
	
	// procura pelo codigo para ver se o carro já foi cadastrado
	achei = false;
	for (int x=0; x<listaCarros.size(); x++)
	{
		if (listaCarros[x].placa == registro.placa)
		{
			achei = true;
			posicao = x;
			registro = listaCarros[x];
			break;
		}
	}
	
	if (achei)
	{
		// se achou o registro mostra os dados
		 gotoxy(20,8);
		cout << registro.categoria;
        	 gotoxy(20,9);
		cout << registro.marca;
        	 gotoxy(20,10);
		cout << registro.modelo;
        	 gotoxy(20,11);
		cout << registro.ano_fabricacao;
        	 gotoxy(20,12);
		cout << registro.cor;
        	 gotoxy(20,13);
		cout << registro.responsavel_legal;
		
		// pergunta se deseja alterar ou excluir
        resp = perguntar(11, 14, "Deseja alterar/excluir/voltar (A/E/V) :");
		if (resp == "A")
        {
        	
        	// o usuário deseja alterar os dados do livro
			// limpa a area para entrar os novos dados
            limparArea(20, 8, 69, 9);
            fflush(stdin);
            
	    //GRUPO MESSIAS,WILLIAM,NATHALIA (Caso alguem copie)
            cout << "Categoria: ";
            getline(cin, registro.categoria);
            cout << "Marca: ";
            getline(cin, registro.marca);
            cout << "Modelo: ";
            getline(cin, registro.modelo);
            cout << "Ano de Fabricacao: ";
            cin >> registro.ano_fabricacao;
            cout << "Cor: ";
            cin >> registro.cor;
            cout << "Responsável Legal do carro: ";
            cin >> registro.responsavel_legal;
	    	fflush(stdin);
            
            // solicita confirmaçao da alteração
            resp = perguntar(11, 14, "Confirma alteracao (S/N) :");

            if (resp == "S")
            {
                listaCarros[posicao] = registro;
            }
		}
		else if (resp == "E")
		{
			// o usuário deseja excluir o livro
			resp = perguntar(11,10,"Confirma exclusao (S/N) :");
			if (resp == "S")
			{
				listaCarros.erase(listaCarros.begin()+posicao);
			}
		}
	}
	else
	{
		// se não achou, pergunta se deseja cadastrar um novo livro
		resp = perguntar(11,14,"Carro nao encontrado. Cadastrar (S/N) :");
		
		if (resp == "S")
        {
            fflush(stdin);
            
            gotoxy(22,8); 
            getline(cin, registro.categoria);
            
            gotoxy(18,9); 
            getline(cin, registro.marca);
            
            gotoxy(19,10); 
            getline(cin, registro.modelo);
            
            gotoxy(27,11);
            cin >> registro.ano_fabricacao;
            
            gotoxy(16,12);
            cin >> registro.cor;
            
            gotoxy(30,13);
            cin >> registro.responsavel_legal;
            fflush(stdin);
            
            resp = perguntar(11, 14, "Confirma cadastro (S/N) :");

            if (resp == "S")
            {
                listaCarros.push_back(registro);
            }
		}
	}
	
}


//*****************************************************************************************************************************//
//*****************************************************************************************************************************//



void listarCarros()
{
    desenharMoldura(10, 5, 70, 15);
    centralizar("Lista de Carros", 6, 10, 70);

    if (listaCarros.empty())
    {
        cout << "Nenhum Carro cadastrado.";
    }
    else
    {
        for (int i = 0; i < listaCarros.size(); i++)
        {
            gotoxy(11, 7 + 8 * i); cout << i + 1 << "° veiculo :";
            gotoxy(11, 8 + 8 * i); cout << "Placa: " << listaCarros[i].placa;
            gotoxy(11, 9 + 8 * i); cout << "Categoria: " << listaCarros[i].categoria;
            gotoxy(11, 10 + 8 * i); cout << "Marca: " << listaCarros[i].marca;
            gotoxy(11, 11 + 8 * i); cout << "Modelo: " << listaCarros[i].modelo;
            gotoxy(11, 12 + 8 * i); cout << "Ano de fabricacao: " << listaCarros[i].ano_fabricacao;
            gotoxy(11, 13 + 8 * i); cout << "Cor: " << listaCarros[i].cor;
            gotoxy(11, 14 + 8 * i); cout << "Responsavel legal: " << listaCarros[i].responsavel_legal;
			
        }
    }
    cin.ignore();
}



//*****************************************************************************************************************************//
//*****************************************************************************************************************************//



main()
{
    setlocale(LC_ALL, "Portuguese");

    string op;

    vector<string> menuPrincipal;
    menuPrincipal.push_back("1 - Cadastrar Carros");
    menuPrincipal.push_back("2 - Listar Carros  ");
    menuPrincipal.push_back("0 - Sair           ");

    while (true)
    {
        clrscr();
        desenharMoldura(1, 1, 80, 25);
        centralizar("Cadastro de Veículos", 2, 1, 80);
        op = mostrarMenu(2, 3, menuPrincipal);

        if (op == "0")
            break;
        if (op == "1")
            cadastroVEICULO();
        if (op == "2")
            listarCarros();
    }

    return 0;
}

