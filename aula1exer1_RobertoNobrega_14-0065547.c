#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//incompleto, nem sequer roda, sem tempo para terminar
struct dono
{
  long long int cpf;
  char nome[50];

}typedef proprietario;

struct carro
{
  proprietario pessoa;
  char modelo[20];
  char placa[7];
}typedef automovel;

void cadastrarVeiculo(int total, automovel *veiculo);
void consultarVeiculo(char placa[7], automovel *carro);
void cadastrarProprietario(automovel *carro);
void consultarProprietario(char placa[7], automovel *carro,int cont);
FILE *abreArquivo(char opcao, char nomeArquivo[30]);
void fecharArquivo(FILE *arquivo);

int main(){
  automovel *carros;
  proprietario *dono;
  FILE *lista;
  lista = abreArquivo('ler', "detran.txt");
  char placa[7];
  int opcao, cont, i;
  while (opcao != 0)
  {
    printf("Digite 1 para Cadastrar um novo Proprietario\n2 para Cadastrar novo Veiculo\n3 para Consultar Veiculo\n4 para Consultar Proprietario\n0 para Sair");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      cadastrarProprietario(carros);
      break;
    case 2:
      cadastrarVeiculo(cont, &carros);
      break;
    case 3:
      printf("\nInsira o numero da placada do carro\n");
      scanf("%s", &placa);
      consultarVeiculo(placa, &carros);
      break;
    case 4:
      printf("\nInsira o numero da placada do carro\n");
      scanf("%s", &placa);
      consultarProprietario(placa, &carros, i);
      break;
    default:
      printf("Opcao invalida, tente novamente!\n");
      break;
    }
    
  }
  return 0;
}


void cadastrarVeiculo(int total, automovel *veiculo){
  char placa[7], modelo[20];
  int i;
  long long int cpf;
  printf("\nInsira o numero da placada do carro\n");
  scanf("%s", &placa);

  for (i = 0; i< total; i++){
    if (placa == veiculo->placa[i])
    {
      printf("Veiculo ja cadastrado no banco de dados.\nSaindo do cadastramento de Veiculo.\n");
      return -1;
    } 
  }
  (veiculo->placa)[i] = placa;
  printf("\ninsira o modelo ");
  scanf("%s", &modelo);
  (veiculo->modelo)[i] = modelo;
  consultarProprietario(placa, &veiculo, i);

}

void consultarVeiculo(char placa[7], automovel *carro){


}

void cadastrarProprietario(automovel *carro){

}

void consultarProprietario(char placa[7], automovel *carro, int cont){
  long long int cpf;
  char opcao;
  printf("\nInsira o CPF do Proprietario do Veiculo ");
  while (scanf("%lld", &cpf)!=1)
  {
    printf("CPF invalido, insira novamente");
  }
  for (size_t i = 0; i < cont; i++)
  {
    if(((carro->pessoa)[i].cpf)== cpf){
      printf("cpf já cadastrado, usuario: %s", carro->pessoa.nome);
      printf("\nCadastrar automovel em seu nome?\ns - SIM n - NAO\n");
      scanf("%c", &opcao);
      if (opcao == 's')
      {
        carro->pessoa.cpf[cont] = carro->pessoa.cpf[i];
      }else if(opcao == 'n')
      {
        printf("\nCadastrar em nome de outra pessoa?\ns - SIM n - NAO\n");
        scanf("%c", &opcao);
        if (opcao == 's')
        {
          cadastrarProprietario(carro);
        } 
      }
    }
  }
  
}
FILE *abreArquivo(char opcao, char nomeArquivo[30]){
  FILE *arquivo;
  switch (opcao)
  {
  case 'gravar':
    arquivo = fopen(nomeArquivo, "wt");
    break;
  case 'ler':
  arquivo = fopen(nomeArquivo, "rt");
    break;
  case 'adicionar':
  arquivo = fopen(nomeArquivo, "a");
  break;
  }
  if (arquivo == NULL)
  {
    printf("Nao foi possivel abrir o arquivo");
    exit(0);
  }
  return arquivo;
  
}
void fecharArquivo(FILE *arquivo){
  fclose(arquivo);
}
