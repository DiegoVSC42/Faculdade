public class Teste {

    public static void main(String[] args){
        System.out.println("Hello World");

        int valor = 0;
        for(int i = 0; i < 10; i++){
            System.out.println(valor);

            if(par(valor) == 1){
                System.out.println("É par");
            }else{
                System.out.println("É ímpar");
            }
            valor++;
        }

    }
    public static int par(int valor){

        if(valor%2==0)
            return 1;
        return 0;
    }
}
