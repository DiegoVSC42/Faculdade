import java.util.Scanner;

public class Simpletron {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String valor = scanner.nextLine();

        switch (valor){

            //READ
            case "10":
                break;
            //WRITE
            case "11":
                break;
            //LOAD
            case "20":
                break;
            //STORE
            case "21":
                break;
            //ADD
            case "30":
                break;
            //SUBTRACT
            case "31":
                break;
            //DIVIDE
            case "32":
                break;
            //MULTIPLY
            case "33":
                break;
            //BRANCH
            case "40":
                break;
            //BRANCHNEG
            case "41":
                break;
            //BRANCHZERO
            case "42":
                break;
            //HALT
            case "43":
                break;
            case "-9999":
                System.out.println("*** Programa carregado ***");
                System.out.println("*** Iniciando a execução do programa ***");
                break;
            default:
                System.out.println("Opcao Invalida");
                break;

        }
    }
}
