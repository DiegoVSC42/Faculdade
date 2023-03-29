import java.util.Scanner;
import java.util.ArrayList;


public class Simpletron {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int[] vetor = new int[100];
        int parameter;
        int acc = 0;
        ArrayList ip = new ArrayList();

        do{
            System.out.println("Digite o valor do operando: ");
            String operator = scanner.nextLine();
            char caractere1 = operator.toCharArray()[0];
            char caractere2 = operator.toCharArray()[1];
            String aux = caractere1.concat(caractere2);
            System.out.println("O aux é: " + aux);
            switch (aux) {

                if(aux == "-99"){
                    aux = "-9999";
                }
                //READ
                case "10":

                    System.out.println("Digite o valor do parametro");
                    parameter = scanner.nextInt();
                    System.out.println("Digite o valor a ser armazenado");

                    vetor[parameter] = scanner.nextInt();
                    System.out.println("O valor do vetor é: " + vetor[parameter]);
                    break;
                //WRITE
                /*case 11:

                    System.out.println("Digite o valor do parametro");
                    parameter = scanner.nextInt();
                    System.out.println("O valor no endereço " + parameter + " é " + vetor[parameter]);

                    break;
                //LOAD
                case 20:
                    System.out.println("Digite o valor do parametro");
                    parameter = scanner.nextInt();
                    acc = vetor[parameter];
                    break;
                //STORE
                case 21*/:
                    System.out.println("Digite o valor do parametro");
                    parameter = scanner.nextInt();
                    vetor[parameter] = acc;
                    break;
                case -9999:
                    System.out.println("Finalizando o programa");
                    break;
                default:
                    System.out.println("Operador invalido");
                    break;
            }
            System.out.println();
        }while(operator != -9999);
    }
}
