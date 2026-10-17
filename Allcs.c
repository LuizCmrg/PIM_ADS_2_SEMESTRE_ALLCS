#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char clienteCadastro_nome[100];
    char clienteCadastro_cpf[12];
    char clienteCadastro_email[100];
    char clienteCadastro_telefone[20];
    char clienteCadastro_dataNascimento[15];
    char clienteCadastro_endereco[100];
} Cliente;

typedef struct {
    int id;
    int cliente_id; 
    char drone_cadastro_marca[50];
    char drone_cadastro_modelo[50];
    char drone_cadastro_numSerie[50];
    char drone_cadastro_status[50];
    float drone_cadastro_horasvoo;
    char data_compra[50];
} Drone;

int main() {
    int opcaoServicos_menu = 0;
    int opcaoServicos = 0;
    int opcao_menu_principal = 0;

    Cliente cliente[100] = {
        {1, "Ana Silva", "12345678901", "ana@email.com", "11988881111", "10/05/1995", "Rua A, 100"},
        {2, "Carlos Souza", "98765432109", "carlos@email.com", "11977772222", "15/08/1988", "Rua B, 200"}
    };
    int totalCadastrados = 2;
    int totalClientes = 2;

    Drone drone[100] = {
        {1, 1, "DJI", "Phantom 4", "DRN-1001", "Ativo", 12.5f, "10/01/2025"},
        {2, 2, "DJI", "Mavic Air 2", "DRN-1002", "Ativo", 5.0f, "20/03/2025"}
    };
    int estoque_drones = 2;

    int condicaoConsulta;
    int condicaoVinculoDrone = 0;
    char drone_numSerie_manut[20];

    do {
        printf("\n========================================\n");
        printf("       ALLLCS DRONES SOLUTIONS\n");
        printf("   [O NOSSO CÉU NÃO CONHECE LIMITES]\n");
        printf("========================================\n");

        printf("1. Cadastrar cliente\n");
        printf("2. Cadastrar equipamento\n");
        printf("3. Consultar cadastro\n");
        printf("4. Serviços\n");
        printf("5. Sair\n");

        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_menu_principal);

        switch (opcao_menu_principal) {

            case 1:
                printf("\n >>>>>> CADASTRO DE CLIENTES ALLCS <<<<<<\n");

                printf("Digite o nome do cliente: ");
                scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_nome);

                printf("Digite os 11 Numeros do CPF do cliente:\n");
                scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_cpf);

                printf("Digite o email do cliente:\n");
                scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_email);

                printf("Digite a data de nascimento do cliente:\n");
                scanf("%s", cliente[totalCadastrados].clienteCadastro_dataNascimento);

                printf("Digite o endereço do cliente:\n");
                scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_endereco);

                totalClientes++;
                cliente[totalCadastrados].id = totalClientes;
                
                printf("\nCliente cadastrado com sucesso!!!\n");
                printf("O id do cliente cadastrado é %d\n", totalClientes);
            
                totalCadastrados++;
                break;

            case 2:
                printf("\n >>>>>> CADASTRO DE EQUIPAMENTOS ALLCS <<<<<<\n");

                printf("\n Digite o modelo do Drone: \n  ");
                scanf(" %[^\n]", drone[estoque_drones].drone_cadastro_modelo);

                printf("\nMarca do Drone: \n ");
                scanf(" %[^\n]", drone[estoque_drones].drone_cadastro_marca);

                printf("\nDigite o numero de série do Drone: \n ");
                scanf(" %[^\n]", drone[estoque_drones].drone_cadastro_numSerie);

                printf("\nDigite aqui as horas de voo do Drone:\n ");
                scanf("%f", &drone[estoque_drones].drone_cadastro_horasvoo);

                printf("\nDigite a data de compra:\n  ");
                scanf(" %[^\n]", drone[estoque_drones].data_compra);

                drone[estoque_drones].id = estoque_drones + 1;

                printf("\n Este equipamento é vinculado a algum cliente? \n Digite 1 para vincular ao ID do cliente.\n Digite 2 para seguir com o cadastro do equipamento.\n ");
                scanf("%d", &condicaoVinculoDrone);

                if(condicaoVinculoDrone == 1){
                    int busca_vinculo_drone = 0;
                    printf("\n Digite o ID do cliente: ");
                    scanf("%d", &busca_vinculo_drone);
                    
                    int i = 0;
                    int encontrado_vinculo = 0;

                    for(i = 0; i < totalCadastrados; i++){ 
                        if(cliente[i].id == busca_vinculo_drone) { 
                            encontrado_vinculo = 1;
                            drone[estoque_drones].cliente_id = cliente[i].id; 
                            
                            printf("Cliente localizado!");
                            printf("\n--- Cliente ID: %d ---\n", cliente[i].id);
                            printf("Cliente: %s\n", cliente[i].clienteCadastro_nome);
                            printf("CPF: %s\n", cliente[i].clienteCadastro_cpf);
                            printf("Email: %s\n", cliente[i].clienteCadastro_email);
                            printf("Data de nascimento: %s\n", cliente[i].clienteCadastro_dataNascimento);
                            printf("Endereço: %s\n", cliente[i].clienteCadastro_endereco);
                            break;
                        }
                    }

                    while(encontrado_vinculo == 0) {
                        printf("\nAviso: Cliente com ID não encontrado.\n");
                        printf("Deseja:\n");
                        printf("1 - Digitar outro ID.\n");
                        printf("2 - Cadastrar um novo cliente agora e vincular.\n");
                        printf("3 - Prosseguir com o cadastro do drone sem vinculo.\n");

                        int condicao_vinculo_menu;
                        scanf("%d", &condicao_vinculo_menu);

                        if(condicao_vinculo_menu == 1){
                            printf("Digite novamente o ID do cliente: ");
                            scanf("%d", &busca_vinculo_drone);

                            for(i = 0; i < totalCadastrados; i++){ 
                                if(cliente[i].id == busca_vinculo_drone) { 
                                    encontrado_vinculo = 1;
                                    drone[estoque_drones].cliente_id = cliente[i].id; 
                                    
                                    printf("Cliente localizado!");
                                    printf("\n--- Cliente ID: %d ---\n", cliente[i].id);
                                    printf("Cliente: %s\n", cliente[i].clienteCadastro_nome);
                                    printf("CPF: %s\n", cliente[i].clienteCadastro_cpf);
                                    printf("Email: %s\n", cliente[i].clienteCadastro_email);
                                    printf("Data de nascimento: %s\n", cliente[i].clienteCadastro_dataNascimento);
                                    printf("Endereço: %s\n", cliente[i].clienteCadastro_endereco);
                                    break;
                                }
                            }
                        } 
                        else if(condicao_vinculo_menu == 2){
                            printf("\n >>>>>> CADASTRO DE CLIENTES ALLCS <<<<<<\n");

                            printf("Digite o nome do cliente: ");
                            scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_nome);

                            printf("Digite os 11 Numeros do CPF do cliente:\n");
                            scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_cpf);

                            printf("Digite o email do cliente:\n");
                            scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_email);

                            printf("Digite a data de nascimento do cliente:\n");
                            scanf("%s", cliente[totalCadastrados].clienteCadastro_dataNascimento);

                            printf("Digite o endereço do cliente:\n");
                            scanf(" %[^\n]", cliente[totalCadastrados].clienteCadastro_endereco);

                            totalClientes++;
                            cliente[totalCadastrados].id = totalClientes;
                            drone[estoque_drones].cliente_id = cliente[totalCadastrados].id;

                            totalCadastrados++;
                            encontrado_vinculo = 1;
                            printf("\nCliente cadastrado e vinculado com sucesso!\n");
                        } 
                        else if(condicao_vinculo_menu == 3){
                            drone[estoque_drones].cliente_id = 0;
                            encontrado_vinculo = 1;
                            printf("\nProsseguindo sem vínculo de cliente...\n");
                        }
                        else {
                            printf("Opção inválida!\n");
                        }
                    }

                } else if(condicaoVinculoDrone == 2){
                    drone[estoque_drones].cliente_id = 0;
                }
                
                printf("\nDrone cadastrado com sucesso!!!\n");
                estoque_drones++;
                break;

            case 3: {
                printf("\n >>>> CONSULTA <<<<<\n");
                printf("Consulta de clientes - digite 1\n");
                printf("Consulta de drones - digite 2\n");
                printf("Para realizar alteração em algum cadastro - Digite 3 \n ");
                printf("Opcao: ");
                scanf("%d", &condicaoConsulta);

                if (condicaoConsulta == 1) {
                    char busca_clientes[50];
                    if (totalCadastrados >= 1) {
                        printf("\n Digite abaixo o CPF do cliente que deseja localizar:\n  ");
                        scanf("%s", busca_clientes);

                        int i;
                        int encontrado_cliente = 0;

                        for (i = 0; i < totalCadastrados; i++) {
                            if (strcmp(cliente[i].clienteCadastro_cpf, busca_clientes) == 0) {
                                encontrado_cliente = 1;
                                printf("\nSucesso! Cliente encontrado na posição %d.\n", i);

                                printf("\n--- Cliente ID: %d ---\n", cliente[i].id);
                                printf("Cliente: %s\n", cliente[i].clienteCadastro_nome);
                                printf("CPF: %s\n", cliente[i].clienteCadastro_cpf);
                                printf("Email: %s\n", cliente[i].clienteCadastro_email);
                                printf("Data de nascimento: %s\n", cliente[i].clienteCadastro_dataNascimento);
                                printf("Endereço: %s\n", cliente[i].clienteCadastro_endereco);
                            }
                        }
                        if (encontrado_cliente == 0) {
                            printf("\nAviso: Nenhum cliente com o CPF '%s' foi encontrado.\n", busca_clientes);
                        }
                    } else {
                        printf("\nNenhum cliente cadastrado.\n");
                    }

                } else if (condicaoConsulta == 2) {
                    char busca[50];
                    int encontrado = 0;
                    printf("Digite o numero de serie do drone que deseja buscar: ");
                    scanf("%s", busca);

                    int i;
                    for (i = 0; i < estoque_drones; i++) {
                        if (strcmp(drone[i].drone_cadastro_numSerie, busca) == 0) {
                            printf("\nSucesso! Drone encontrado na posição %d do estoque.\n", i);
                            encontrado = 1;

                            printf("\n--- Drone ---\n");
                            printf("Modelo: %s\n", drone[i].drone_cadastro_modelo);
                            printf("Marca: %s\n", drone[i].drone_cadastro_marca);
                            printf("Número de série: %s\n", drone[i].drone_cadastro_numSerie);
                            printf("Horas de voo: %.2f\n", drone[i].drone_cadastro_horasvoo);
                            printf("Data de compra: %s\n", drone[i].data_compra);
                            break;
                        }
                    }

                    if (encontrado == 0) {
                        printf("\n Aviso: Nenhum drone com a serie '%s' foi localizado no sistema.\n", busca);
                    }
                }
                else if (condicaoConsulta == 3){
                    int opcao_alter_cadastro = 0;
                    int condicao_alter_cadastro = 0;

                    printf("Deseja alterar o cadastro do cliente?\n ");
                    printf("Digite 1 para sim\n");
                    printf("Digite 2 para não\n");
                    scanf("%d", &condicao_alter_cadastro);
                   
                    if(condicao_alter_cadastro == 1){
                        int id_busca_alt = 0;
                        printf("Digite o ID do cliente que deseja alterar: ");
                        scanf("%d", &id_busca_alt);

                        int i;
                        int achou_alt = -1;
                        for(i = 0; i < totalCadastrados; i++){
                            if(cliente[i].id == id_busca_alt){
                                achou_alt = i;
                                break;
                            }
                        }

                        if(achou_alt != -1){
                            printf("Qual informação deseja alterar?\n");
                            printf("1 - Nome\n");
                            printf("2 - CPF\n");
                            printf("3 - Email\n");
                            printf("4 - Data de Nascimento\n");
                            printf("5 - Endereco\n");
                            printf("Digite sua opcao: ");
                            scanf("%d", &opcao_alter_cadastro);

                            switch(opcao_alter_cadastro){
                                case 1:
                                    printf("Digite o novo nome: ");
                                    scanf("%[^\n]", cliente[achou_alt].clienteCadastro_nome);
                                    break;
                                case 2:
                                    printf("Digite o novo CPF: ");
                                    scanf("%s", cliente[achou_alt].clienteCadastro_cpf);
                                    break;
                                case 3:
                                    printf("Digite o novo email: ");
                                    scanf("%s", cliente[achou_alt].clienteCadastro_email);
                                    break;
                                case 4:
                                    printf("Digite a nova data de nascimento: ");
                                    scanf("%s", cliente[achou_alt].clienteCadastro_dataNascimento);
                                    break;
                                case 5:
                                    printf("Digite o novo endereço: ");
                                    scanf(" %[^\n]", cliente[achou_alt].clienteCadastro_endereco);
                                    break;
                                default:
                                    printf("Opção inválida!\n");
                                    break;
                            }
                        } else {
                            printf("Cliente com ID não encontrado!\n");
                        }
                    }
                }
                break;
            }

            case 4: {
                printf("\n >>>> ALCCS SERVIÇOS <<<<\n");
                printf("1 - Manutenção\n");
                printf("2 - Garantia\n");
                printf("3 - Serviços\n");
                printf("Opcao: ");
                scanf("%d", &opcaoServicos);

                char clienteCadastro_telefone_servicos[20];

                if (opcaoServicos == 1) {
                    printf("\n SERVIÇOS -- MANUTENÇÃO \n ");
                    printf("Digite o numero de série do equipamento que deseja que seja feita a Manutenção: \n ");
                    scanf("%s", drone_numSerie_manut);
                    int i = 0;
                    for(i = 0; i < estoque_drones; i++) {
                        if(strcmp(drone[i].drone_cadastro_numSerie, drone_numSerie_manut) == 0) {
                            printf("\n ---Drone localizado ---\n ");
                            printf("Ordem serviço gerada: %s\n", drone_numSerie_manut);
                            printf("Preencha o formulário de Manutenção para ordem de serviço. \n");
                            printf("--- FORMULÁRIO DE MANUTENÇÃO DE DRONE ---\n\n");
                            printf("Drone: Qual o modelo do drone?\n");
                            printf("Horas: Quantas horas de voo desde a última revisão?\n");
                            printf("Baterias: Qual o nível atual de integridade das baterias?\n");
                            printf("Hélice: Há trincas ou desgaste nas hélices?\n");
                            printf("Motores: Os motores apresentam ruídos ou vibrações anormais?\n");
                            printf("Câmera: O gimbal e a câmera estão funcionando perfeitamente?\n");
                            printf("GPS: O sinal de GPS e a bússola foram calibrados?\n");
                            printf("Firmware: O firmware e os aplicativos estão atualizados?\n");
                            printf("Limpeza: Foi feita a limpeza de poeira e resíduos?\n");
                            printf("Status: O drone está apto para o próximo voo?\n");
                        }
                    }
                } else if (opcaoServicos == 2) {
                    printf("Acionando a garantia...\n");

                } else if (opcaoServicos == 3) {
                    printf("\n>>>>> - SERVIÇOS ALLCS - <<<<<\n");
                    printf("Deseja um serviço de filmagem e fotografia? Digite 1:\n");
                    printf("Deseja um serviço de espetáculo de drones? Digite 2:\n");
                    printf("Dúvidas? Digite 3:\n");
                    scanf("%d", &opcaoServicos_menu);

                    if (opcaoServicos_menu == 1) {
                        printf("Você selecionou a opção 1!\n");
                        printf("Temos uma vasta gama de itens que atendem a linha de filmagem 4K e fotografia dinâmica.\n");
                    } else if (opcaoServicos_menu == 2) {
                        printf("Você selecionou a opção 2!\n");
                        printf("Para o espetáculo de drones, precisamos de algumas informações....\n");
                    } else if (opcaoServicos_menu == 3) {
                        printf("Gostaria de conversar com um atendente? Digite seu contato (XX)-XXXXXXXXX:\n");
                        scanf("%19s", clienteCadastro_telefone_servicos);
                        printf("Você digitou %s\n", clienteCadastro_telefone_servicos);
                    }
                }
                break;
            }

            case 5:
                printf("\n>> Encerrando o Sistema. Obrigado!\n");
                break;

            default:
                printf("\nOpção invalida! Tente novamente.\n");
                break;
        }

    } while (opcao_menu_principal != 5);

    return 0;
}