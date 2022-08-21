import java.util.Scanner;
import java.util.ArrayList;


public class Spt {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int[] vetor = new int[100];
        int parameter;
        int acc = 0;
        ArrayList<Integer> ip = new ArrayList<Integer>();

        for(int i = 0; i < 100;i++){
            ip.add(0);
        }

        String valor;
        System.out.println("                        *** Bem vindo ao Simpletron!                                 ***\n" +
                           "                        *** Por favor insira uma instrução (ou data word)            ***\n" +
                           "                        *** por vez em seu programa. Eu vou digitar o número         ***\n" +
                           "                        *** o número de alocação e o ponto de interrogação (?).      ***\n" +
                           "                        *** Então você digita a palavra para a alocação.             ***\n" +
                           "                        *** Digite o número -9999 para parar indicar o fim do        ***\n" +
                           "                        *** seu programa.                                            ***");
        do{

            System.out.println("Digite o valor do operando: ");
            valor = scanner.nextLine();
            //System.out.println("O operador é : " + valor);
            String operador = valor.substring(0, 2);
            //System.out.println("O operador é: " + operador);
            String parametro = valor.substring(2, 4);
            int parametro_int = Integer.parseInt(parametro);
            //System.out.println("O parametro é: " + parametro);
           switch (operador){
               //READ
               case "10":

                   System.out.println("Digite a palavra a ser inserida: ");
                   int palavra = scanner.nextInt();
                   ip.add(parametro_int,palavra);
                   break;
               //WRITE
               case "11":
                   palavra = ip.get(parametro_int);
                   System.out.println("A palavra é: " + palavra );
                   break;
               //LOAD
               case "20":
                   acc = ip.get(parametro_int);
                   break;
               //Store
               case "21":
                   ip.add(parametro_int,acc);
                   break;
               //ADD
               case "30":
                   acc = acc + ip.get(parametro_int);
                   break;
               //SUBTRACT
               case "31":
                   acc = acc - ip.get(parametro_int);
                   break;
               //DIVIDE
               case "32":
                   acc = acc / ip.get(parametro_int);
                   break;
               //Multiply
               case "33":
                   acc = acc * ip.get(parametro_int);
                   break;
               //BRANCH
               case "40":
                   acc = acc * ip.get(parametro_int);
                   break;
               case"-9999":
                   System.out.println("Encerrando o programa");
                   break;
               default:
                   System.out.println("Valor invalido");
                   break;
           }

        }while(valor.equals("-9999") == false);
   }
}

