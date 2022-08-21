package br.poo.apinewbank.repository;

import br.poo.apinewbank.service.CostumerService;
import br.poo.apinewbank.entity.CostumerEntity;
import br.poo.apinewbank.entity.UserEntity;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

@Repository
public class CostumerRepository {
    private List<Integer> allAccountNumbers = new ArrayList<>();

    private boolean binarySearchAccountNumber(int accountNumber, int low, int high) {
        if (high > low) {
            int mid = (high + low)/2;
            if (accountNumber > allAccountNumbers.get(mid)) {
                return binarySearchAccountNumber(accountNumber, mid + 1, high);
            } else if (accountNumber < allAccountNumbers.get(mid)) {
                return binarySearchAccountNumber(accountNumber, low, mid - 1);
            } else {
                return true;
            }
        }
        return allAccountNumbers.get(low) == accountNumber;
    }

    public boolean accountAlreadyExists(int accountNumber) {
        if (allAccountNumbers.size() > 0) {
            return binarySearchAccountNumber(accountNumber, 0, allAccountNumbers.size() - 1);
        } else {
            return false;
        }

    }


    private void binaryIncludeAccountNumber(int accountNumber, int low, int high) {
        if (high > low) {
            int mid = (high + low)/2;
            if (accountNumber > allAccountNumbers.get(mid)) {
                binaryIncludeAccountNumber(accountNumber, mid + 1, high);
                return;
            } else {
                binaryIncludeAccountNumber(accountNumber, low, mid - 1);
                return;
            }
        }

        if (accountNumber > allAccountNumbers.get(low)) {
            allAccountNumbers.add(low + 1, accountNumber);
            return;
        } else {
            allAccountNumbers.add(low, accountNumber);
            return;
        }
    }

    public void includeNewAccountNumber(int accountNumber) {
        if (allAccountNumbers.size() > 0) {
            binaryIncludeAccountNumber(accountNumber, 0, allAccountNumbers.size() - 1);
        } else {
            allAccountNumbers.add(accountNumber);
        }
    }
    public List<UserEntity> get() {
        //TODO: Consultar no banco de dados os computadores do
        //      tipo Simpletron
        CostumerService accountN = new CostumerService();
        String acc = accountN.generateAccountNumber();
        UserEntity costumer = new UserEntity();
        costumer.setName("Diego");
        costumer.setPassword("456789");
        costumer.setAccountNumber(acc);
        costumer.setCPF("123456789-01");
        List<UserEntity> result = new ArrayList<>();
        result.add(costumer);

        return result;
    }

    public void save(CostumerEntity user) {
        //TODO: Gravar os dados do novo computador no banco de dados

        /*ArrayList <CostumerEntity> DataBase = new ArrayList<CostumerEntity>();
        DataBase.add(costumer.getName());
        DataBase.add(user.getBalance());
        DataBase.add(user.getPassword());*/
    }

    public void update(CostumerEntity computer) {
        //TODO: 1) RECUPERAR O DADO DO BANCO DE DADOS;
        //      2) ALTERAR OS DADOS EM MEMORIA;
        //      3) GRAVAR OS DADOS ALTERADOS NO BANCO DE DADOS.
    }

    public void delete(long id) {
        //TODO: REMOVER O REGISTRO DO BANCO DE DADOS BASEADO NO IDENTIFICADOR
        //      UNICO.
    }


}
