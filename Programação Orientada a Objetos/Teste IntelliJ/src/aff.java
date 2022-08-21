import jdk.swing.interop.SwingInterOpUtils;

import java.util.Scanner;


public class aff {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int[] ip = new int[100];
        int acc = 0;
        //int[] Manager = new int[100];
        int valor = 0;
        System.out.println("                        *** Bem vindo ao Simpletron!                                 ***\n" +
                "                        *** Por favor insira uma instrução (ou data word)            ***\n" +
                "                        *** por vez em seu programa. Eu vou digitar o número         ***\n" +
                "                        *** o número de alocação e o ponto de interrogação (?).      ***\n" +
                "                        *** Então você digita a palavra para a alocação.             ***\n" +
                "                        *** Digite o número -9999 para parar indicar o fim do        ***\n" +
                "                        *** seu programa.                                            ***");

        for (int i = 0; valor > -9999; i++) {

            System.out.print("0" + i + " ? ");
            valor = scanner.nextInt();
            if (valor > -9999){
                ip[i] = valor;
            }else{
                System.out.println("                        *** Programa carregado ***\n" +
                        "                        *** Iniciando a execução do programa ***");
            }
        }

        for (int i = 0; i < 100; i++) {

            //System.out.println("Ip: "+ ip[i]);
            /*for (int j = 0; j < 100; j++) {
                System.out.print(" " + ip[j]);
            }*/
            int operator = ip[i]/100;
            //System.out.println("Operador: " + operator);
            int parameter = ip[i]%100;
            //System.out.println("Parametro: " + parameter);
            //System.out.println("i = " + i +" parametro = " + parameter);

            switch (operator) {
                //READ
                case 10:
                    System.out.println("Executando processo: " + ip[i]);
                    System.out.println("Digite o valor a ser inserido");
                    int palavra = scanner.nextInt();
                    ip[parameter] = palavra;
                    break;
                //WRITE
                case 11:
                    //System.out.println("ENTREI");
                    palavra = ip[parameter];
                    System.out.println("O numero é: " + palavra);
                    break;
                //LOAD
                case 20:
                    acc = ip[parameter];
                    //System.out.println("Acumulador: "+acc);
                    break;
                //Store
                case 21:
                    ip[parameter] = acc;

                    break;
                //ADD
                case 30:
                    acc = acc + ip[parameter];

                    break;
                //SUBTRACT
                case 31:
                    acc = acc - ip[parameter];
                    //System.out.println("Acumulador: "+acc);
                    break;
                //DIVIDE
                case 32:
                    acc = acc / ip[parameter];
                    break;
                //Multiply
                case 33:
                    acc = acc * ip[parameter];
                    break;
                //BRANCH
                case 40:

                    i = parameter-1;
                    break;
                case 41:
                    //System.out.println("ENTREI 41 / i antes = "+ i);
                    if(acc < 0)
                        i = parameter-1;
                    //System.out.println("ENTREI 41 / i depois = "+ i);
                    break;
                case 42:
                    //System.out.println("ENTREI 42 / i antes = "+ i);
                    if(acc == 0)
                        i = parameter-1;
                    // System.out.println("ENTREI 42 / i depois = "+ i);
                    break;
                case 43:
                    System.out.println("***Finalizando o programa***");
                    System.exit(0);

            }
        }

    }
}

