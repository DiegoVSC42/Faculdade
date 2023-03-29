package br.iesb.cco.apidemo.repository;

import br.iesb.cco.apidemo.model.SimpletronEntity;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

@Repository
public class SimpletronRepository {

    public List<SimpletronEntity> get() {
        //TODO: Consultar no banco de dados os computadores do
        //      tipo Simpletron
        SimpletronEntity computer = new SimpletronEntity();
        computer.setBrand("Simpletron Computers");
        computer.setDescription("Computador simples do tipo Simpletron V1");
        computer.setName("Simpletron i9");

        List<String> inst = new ArrayList<>();
        inst.add("ADD");
        inst.add("LOAD");
        inst.add("STORE");
        inst.add("SUB");
        inst.add("WRITE");
        inst.add("READ");
        computer.setInstructions(inst);

        List<SimpletronEntity> resultadoDoBanco = new ArrayList<>();
        resultadoDoBanco.add(computer);

        return resultadoDoBanco;
    }

    public void save() {
        save();
    }

    public void save(SimpletronEntity computer) {
        //TODO: Gravar os dados do novo computador no banco de dados
    }

    public void update(SimpletronEntity computer) {
        //TODO: 1) RECUPERAR O DADO DO BANCO DE DADOS;
        //      2) ALTERAR OS DADOS EM MEMORIA;
        //      3) GRAVAR OS DADOS ALTERADOS NO BANCO DE DADOS.
    }

    public void delete(long id) {
        //TODO: REMOVER O REGISTRO DO BANCO DE DADOS BASEADO NO IDENTIFICADOR
        //      UNICO.
    }

}
