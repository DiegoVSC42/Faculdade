######################################################################################################################
#############################################    R   E   S   U   M   O     ###########################################
######################################################################################################################

Pacotes: Lugar para organizar as classes{

    Pacotes de uma api:{
        
        controller:{
            Contem os endpoints
        }
        dto(Data Transfer Object):{
            Contem as classes que convertem para JSON
            
            É o que será devolvido para a WEB, por meio de conversao de um model
        }
        model:{
            Contem as classes que representam tabelas no banco de dados
        }
        repository:{
            Contem as classes com operacoes do banco de dados
        }
        service{
            Contem as clases com regras de negocio
            Exemplo de regra de negocio:{

                Validar se um email está correto: "xxxxx@xxxxx.xxxx"

            }
        }
    }
}
Classe{ 
	
    Tem o mesmo nome do arquivo se for publica, 
    pode ter varias classes em um arquivo mas so uma pode ser publica

    Classe abstrata: Quando se diz o que fazer mas nao como{
        ex: 

            public abstract class{
                abstract void emitirSom();
            }

        todas as classes filhas poderao utilizar o metodo "emitirSom" para fazer polimorfismo
    }
}
Herança: A classe filha utilizar algo da classe pai{
    
    //CostumerPremiumEntity
    //AuthRepository
    //CostumerRepositoryInterface

    Ex:{

        cachorro.emitirsom();"A classe pai precisa ter o metodo emitirSom()"
    }
}
Metodos:   Tipo função em C{
	Composto por 
    retorno-nome(parâmetro){    

    Ex:{
	    Void método(int i){
    }
}
		
Instancia(objeto){ 

	Exemplo de criação de objeto:

    “Animal a1 = new Animal();”
    “new”: equivalente a malloc em C.


    Ou seja, seria a mesma coisa que{

        Animal *p = (animal*)malloc(sizeof(Animal));
    }
}

Polimorfismo: Mesma açao com comportamento diferente{

    //CostumerPremiumEntity
    
    Sobrescrita: Passar por cima do metodo da classe pai e considerar o do filho{

    Ex: 

        Toda arara possui penas, porem arara azul possui penas azuis
    
    }

    Ex{
        Cachorro late e cavalo relincha, os dois sao animais
        mas o comportamento é diferente
    }
}
Encapsulamento: Esconder detalhes que nao sao podem ou nao precisam ser acessados pelo usuario{

    //Entity e DTO 

}

API (Application Programming Interface): Faz a comunicacao entre um software e um site{

    Ex:{

        API do google maps

    }
}

Framework: Conjunto de bibliotecas usadas para compor uma API{

    Ex: { 
        Springboot: Framework java usada para criar API 
    }
}

Verbos:{

    Get: Receber dados{

    }
    Post: Incluir dados{

    }
    Put: Atualizar dados{

    }
    Delete: Remover dados{

    }
}

######################################################################################################################
######################################################################################################################
######################################################################################################################
