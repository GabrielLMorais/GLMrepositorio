#include <iostream> // Biblioteca para executar operações de leitura e gravação em arquivos.
#include <vector> // Biblioteca para Armazenar elementos de um determinado tipo e permite o acesso a qualquer elemento.
#include <algorithm> // Biblioteca para pesquisa, classificação, contagem e manipulação de dados.
using namespace std; // É utilizado para que não se repita o std em todos os comandos padrões da linguagem.

// Registro para os produtos da máquina: 
typedef struct{
 string nomeProduto; // Para gravar o nome do produto.
 double precoProduto; // Para gravar o preço do produto.
 int quantidadeProduto; // Para gravar a quantidade
}Produtos;

// Variáveis globais:
double faturamento = 0; // Variável para armazenar o faturamento da máquina.
int contadorLogin = 0; // Variável para saber qual é a vez que você vai fazer login.
string nomeAdministrador, senhaAdministrador, nomeAdministradorAtual, senhaAdministradorAtual; // Variáveis para acesso em cadastrar e logar.

vector<Produtos> produtosArray; // Declaração do array de produtos de tamanho indefinido.
Produtos produto; // Declaração da variável de produtos.

// Função para verificar se o char não é diferente de (S)Sim ou (N)Não.
char verificardorChar(char continuandoOperacoes){
   //toupper é para deixar o caractere em caixa alta.
  if(toupper(continuandoOperacoes)!='S'){ // Verificar se é diferente de S.
    if(toupper(continuandoOperacoes)!='N'){ // Verificar se é diferente de N.
      continuandoOperacoes = 's'; // Se for diferente de S e N ela recebe s para encerrar a operação.
      cout << "" << endl;
      cout << "Você só pode digitar (S)Sim ou (N)Não!!! \n";
      cout << "Você saiu dessa operação \n";
      cout << "" << endl;
    }
  }
  return continuandoOperacoes; // Retorna a variável para continuar o programa.
}

// Função para adicionar produtos.
void adicionarProduto(){
  char continuarAdicionar; // Variável para armazenar S ou N para saber se vai continuar adicionando.
  cout << "*-=======================Adicionar Produto=====================-* \n";

  do{
    cout << "Digite o nome do produto: ";
    cin >> produto.nomeProduto;
    cout << "Digite o preço do produto: ";
    cin >> produto.precoProduto;
    cout << "Digite a quantidade de produtos: ";
    cin >> produto.quantidadeProduto;
    cout << "" << endl;
    
    produtosArray.push_back(produto); // Adiciona o novo produto na pilha de registros.

    cout << "Produto adicionado com sucesso!!! \n";
    cout << "" << endl;

    cout << "Digite (S)Sim ou (N)Não \n";
    cout << "Você quer parar de adicionar produtos? ";
    cin >> continuarAdicionar;
    continuarAdicionar = verificardorChar(continuarAdicionar); // Chama a função para verificar se é diferente.
    cout << "" << endl;
       //toupper é para deixar o caractere em caixa alta.
  }while(toupper(continuarAdicionar)!='S'); // O laço para quando for igual a S.
} 

// Função para listar produtos.
void listarProduto(){
  for(int i = 0; i < produtosArray.size(); i++){ // Size para saber quantas posições do array.
    produto = produtosArray[i]; // produto recebe qual a posição.
    cout << i+1 << "-  Nome: " << produto.nomeProduto << "; Preço: R$ " << produto.precoProduto << "; quantidade: " << produto.quantidadeProduto << "; \n";
  }
  cout << "" << endl;
} 

// Função para repor produtos.
void reporProduto(){
  bool existeRepor = false; // Variável para saber se o valor digita existe.
  int qualRepor, repor; // Variáveis para saber qual produto quer repor, e a quantidade
  cout << "*-=========================Repor Produto=======================-* \n";

  listarProduto(); // Chama a função listar para apresentar os produtos para o usuário.
  
  cout << "Qual produto você deseja repor: ";
  cin >> qualRepor;
  
  // For para percorrer o array.
  for(int i = 0; i < produtosArray.size(); i++){
    // Verifica se o valor digitado existe ou não.
    if(qualRepor-1==i){
      existeRepor = true;
    }else{
      existeRepor = false;
    }
  }
  // Se for verdade ele continua o código. Se não ele apresente que o valor não existe.
  if(existeRepor==true){
    cout << "Quantidade que você deseja repor: ";
    cin >> repor;
    cout << "" << endl;
    
    produtosArray[qualRepor-1].quantidadeProduto += repor; // Adiciona o valor digitado na quantidade do produto.
  
    cout << "Produtos repostos com sucesso!!! \n";
    cout << "" << endl;
  }else{
    cout << "" << endl;
    cout << "O produto escolhido não existe!! \n";
    cout << "" << endl;
  }
} 

// Função para excluir produtos.
void excluirProduto(){
  bool existeExcluir = false; // Variável para saber se o valor digita existe.
  int qualExcluir; // Variável para saber qual produto quer excluir.
  cout << "*-=======================Remover Produto=======================-* \n";

  listarProduto(); // Chama a função listar para apresentar os produtos para o usuário.
  
  cout << "Qual produto você deseja remover: ";
  cin >> qualExcluir;
  cout << "" << endl;

  // For para percorrer o array.
  for(int i = 0; i < produtosArray.size(); i++){
    // Verifica se o valor digitado existe ou não.
    if(qualExcluir-1==i){
      existeExcluir = true;
    }else{
      existeExcluir = false;
    }
  }
  // Se for verdade ele continua o código. Se não ele apresente que o valor não existe.
  if(existeExcluir==true){
    // For para percorrer o array e jogar o valor escolhido na última posição.
    for(int i = qualExcluir-1; i<produtosArray.size() - 1; i++) {
      produtosArray[i] = produtosArray[i + 1];
    }
    produtosArray.pop_back(); // Exclui a última posição do array.

    cout << "Produto(s) removido(s) com sucesso!!! \n";
    cout << "" << endl;
  }else{
    cout << "O produto escolhido não existe!! \n";
    cout << "" << endl;
  }
} 

// Função para editar produtos.
void editarProduto(){
  bool existeEditar = false; // Variável para saber se o valor digita existe. 
  int qualEditar; // Variável para saber qual produto quer editar.
  string editaNome; // Variável que recebe o novo nome do produto.
  double editaPreco; // Variável que recebe o novo preço do produto.
  cout << "*-========================Editar Produto=======================-* \n";

  listarProduto(); // Chama a função listar para apresentar os produtos para o usuário.
  
  cout << "Qual produto você deseja editar: ";
  cin >> qualEditar;

  // For para percorrer o array.
  for(int i = 0; i < produtosArray.size(); i++){
    // Verifica se o valor digitado existe ou não.
    if(qualEditar-1==i){
      existeEditar = true;
    }else{
      existeEditar = false;
    }
  }
  // Se for verdade ele continua o código. Se não ele apresente que o valor não existe.
  if(existeEditar==true){
    cout << "Digite o novo nome do produto: ";
    cin >> editaNome;
    cout << "Digite o novo preço do produto: ";
    cin >> editaPreco;
    cout << "" << endl;
  
    produtosArray[qualEditar-1].nomeProduto = editaNome; // O nome do produto recebe o novo nome.
    produtosArray[qualEditar-1].precoProduto = editaPreco; // O preço do produto recebe o novo preço.

    cout << "Produto editado com sucesso!!! \n";
    cout << "" << endl;
  }else{
    cout << "" << endl;
    cout << "O produto escolhido não existe!! \n";
    cout << "" << endl;
  }  
} 

// Função para listar o faturamento da máquina e o que ela pode faturar.
void listarFaturamento(){
  double podeFaturar; // Variável que vai armazenar o valor que a máquina pode faturar.
  cout << "*-=====================Lista do Faturamento====================-* \n";

  // For para percorrer o array.
  for(int i = 0; i < produtosArray.size(); i++){
    produto = produtosArray[i]; // produto recebe qual a posição.
    podeFaturar = podeFaturar + produto.precoProduto * produto.quantidadeProduto; // Calcula quanto ainda pode faturar.
  }

  cout << "A fatura da máquina é: R$ " << faturamento << " \n";
  cout << "A máquina ainda pode faturar: R$ " << podeFaturar << " \n";
  cout << "" << endl;
} 

// Função do modo administrador.
void modoAdministrador(){
  int opcoesModoAdministrador; // Variável que armazena a opção que o usuário quer.
  cout << "*-======================Modo Administrador=====================-* \n";

  do{
    cout << "*-=====================Opções:=====================-* \n";
    cout << "1- Adicionar Produto; \n";
    cout << "2- Repor Produto; \n";
    cout << "3- Listar Produtos; \n";
    cout << "4- Remover Produto; \n";
    cout << "5- Editar Nome e Preço \n";
    cout << "6- Listar Faturamento e Quanto Pode Faturar; \n";
    cout << "7- Voltar; \n";
    cout << "Digite a opção que você quer (1, 2, 3, 4, 5 ou 6): ";
    cin >> opcoesModoAdministrador;
    cout << "" << endl;

    // Switch Case para saber qual opção foi digitada.
    switch (opcoesModoAdministrador){
      case 1:
          adicionarProduto(); // Chama a função para adicionar produto.
      break;
      case 2:
        // If para caso não existir o produto ele apresentar que não tem nenhum produto.
        if(produtosArray.size()>0){
          reporProduto(); // Chama a função para repor produto.
        }else{
          cout << "Não tem nenhum produto adicionado!! \n";
          cout << "" << endl;
        }
      break;
      case 3:
        cout << "*-======================Lista de Produtos======================-* \n";
        // If para caso não existir o produto ele apresentar que não tem nenhum produto.
        if(produtosArray.size()>0){
          listarProduto(); // Chama a função para listar os produtos.
        }else{
          cout << "Não tem nenhum produto adicionado!! \n";
          cout << "" << endl;
        }
      break;
      case 4:
        // If para caso não existir o produto ele apresentar que não tem nenhum produto.
        if(produtosArray.size()>0){
          excluirProduto(); // Chama a função para excluir produto.
        }else{
          cout << "Não tem nenhum produto adicionado!! \n";
          cout << "" << endl;
        }
      break;
      case 5:
        // If para caso não existir o produto ele apresentar que não tem nenhum produto.
        if(produtosArray.size()>0){
          editarProduto(); // Chama a função para editar o produto.
        }else{
          cout << "Não tem nenhum produto adicionado!! \n";
          cout << "" << endl;
        }
      break;
      case 6:
        // If para caso não existir o produto ele apresentar que não tem nenhum produto.
        if(produtosArray.size()>0){
          listarFaturamento(); // Chama a função para listar o faturamento, e quanto ainda pode faturar.
        }else{
          cout << "Não tem nenhum produto adicionado!! \n";
          cout << "" << endl;
        }
      break;
      case 7: // Case 7 é só para voltar e não apresentar que a opção não existe.
      break;
      default:
        cout << "Você não digitou uma opção existente!!!\n";
      break;
    }
  }while(opcoesModoAdministrador!=7); // O laço para quando for igual a 7.
}

// Função para se registrar e fazer login.
void registrarLogin(){  
  // If para verificar se é o primeiro acesso no modo administrador.
  if(contadorLogin==0){ // Se for o primeiro é para criar a conta
    cout << "*-=========================Criar Conta=========================-* \n";

    cout << "Digite o nome do administrador: ";
    cin >> nomeAdministrador;
    cout << "Crie a senha do administrador: ";
    cin >> senhaAdministrador;
    cout << "" << endl;
  }
  contadorLogin = 1;
  
  if(contadorLogin==1){ // Se não é só entrar na conta.
    cout << "*-=======================Entrar na Conta=======================-* \n";
    
    cout << "Digite o seu nome: ";
    cin >> nomeAdministradorAtual;
    cout << "Digite a sua senha: ";
    cin >> senhaAdministradorAtual;
    cout << "" << endl;

    // Verifica se o nome e senha estão corretos
    if(nomeAdministrador==nomeAdministradorAtual && senhaAdministrador==senhaAdministradorAtual){
      modoAdministrador();
    }else{
      cout << "Senha ou nome de administrador erradas!!! \n";
      cout << "" << endl;
    }
  }
} 

// Função para comprar produtos.
void comprarProduto(){
  bool existeProduto = false; // Variável para saber se o valor digita existe.
  int qualComprar, quantidadeCompra; // Variáveis para saber qual produto quer comprar, e a quantidade.
  char continuarComprar; // Variável para verificar se quer continuar comprando.
  double valorPago, troco; // Variáveis para o valor pago, e o troco.

  do{
    listarProduto(); // Chama a função listar para apresentar os produtos para o usuário.

    cout << "Qual produto você deseja comprar: \n";
    cin >> qualComprar;

    // For para percorrer o array.
    for(int i = 0; i < produtosArray.size(); i++){
      // Verifica se o valor digitado existe ou não.
      if(qualComprar-1==i){
        existeProduto = true;
      }else{
        existeProduto = false;
      }
    }

    // Se for verdade ele continua o código. Se não ele apresente que o valor não existe.
    if(existeProduto==true){
      cout << "Quantos produtos você quer comprar: \n";
      cin >> quantidadeCompra;
  
      cout << "O preço da compra é: R$ ";
      cout << produtosArray[qualComprar-1].precoProduto * quantidadeCompra << "\n";
      cout << "Digite a quantidade que você vai pagar: ";
      cin >> valorPago;
      cout << "" << endl;

      // If para ver se o valor pago precisa de troco ou não, e se não foi pago o suficiente.
      if(valorPago==produtosArray[qualComprar-1].precoProduto * quantidadeCompra){ // Se o valor pago é igual o preço.
        faturamento = faturamento + (produtosArray[qualComprar-1].precoProduto * quantidadeCompra);
        produtosArray[qualComprar-1].quantidadeProduto -=  quantidadeCompra;
        cout << "Compra realizada com sucesso!!! \n";
        cout << "" << endl;
      }else if(valorPago>produtosArray[qualComprar-1].precoProduto * quantidadeCompra){ // Se o valor pago é maior que o preço.
        troco = valorPago - (produtosArray[qualComprar-1].precoProduto * quantidadeCompra);
        produtosArray[qualComprar-1].quantidadeProduto -=  quantidadeCompra;
        cout << "Seu troco é: R$ " << troco << " \n";
        faturamento = faturamento + (produtosArray[qualComprar-1].precoProduto * quantidadeCompra);
        cout << "Compra realizada com sucesso!!! \n";
        cout << "" << endl;
      }else{ // Se o valor é menor que o preço.
        cout << "O valor inserido é menor que o valor da compra! \n";
        cout << "Cancelando a compra... devolvendo o seu dinheiro... \n";
        cout << "Compra cancelada com sucesso!!! \n";
        cout << "" << endl;
      }
    }else{
      cout << "" << endl;
      cout << "O produto escolhido não existe!! \n";
      cout << "" << endl;
    }
    cout << "Digite (S)Sim ou (N)Não \n";
    cout << "Você quer parar de comprar produtos? ";
    cin >> continuarComprar;
    continuarComprar = verificardorChar(continuarComprar); // Chama a função para verificar se é diferente. 
    cout << "" << endl;
       //toupper é para deixar o caractere em caixa alta.
  }while(toupper(continuarComprar)!='S'); // O laço para se for igual a S.
} 

// Função do modo usuário
void modoUsuario(){
  cout << "*-===========================Usuário===========================-* \n";

  comprarProduto(); // Chama a função para comprar produto.
} 

// Parte do corpo do programa.
int main() {
  int opcoesModos; // Variável que armazena a opção escolhida pelo usuário

  do{ 
    cout << "*-=======================Vending Machine=======================-* \n";
    cout << "*-========================Modos:========================-* \n";
    cout << "1- Administrador; \n";
    cout << "2- Usuário; \n";
    cout << "3- Sair do programa; \n";
    cout << "Digite o modo que você quer entrar (1, 2 ou 3): ";
    cin >> opcoesModos;
    cout << "" << endl;

    // Switch Case para saber qual opção foi digitada.
    switch (opcoesModos){
      case 1:
        registrarLogin(); // Chama a função para se registrar ou logar
      break;
      case 2:
        // If para caso não existir o produto ele apresentar que não tem nenhum produto.
        if(produtosArray.size()>0){
          modoUsuario(); // Chama a função do modo usuário
        }else{
          cout << "Não tem nenhum produto adicionado!! \n";
          cout << "" << endl;
        }
      break;
      case 3:
        cout << "Saindo... \n";
      break;
      default:
        cout << "Você não digitou um opção existente!!!\n";
        cout << "" << endl;
      break;
    }
  }while(opcoesModos!=3); // O programa encerra se o laço for igual a 3.
  cout << "Você saiu do programa. Obrigado por usar!!";
}