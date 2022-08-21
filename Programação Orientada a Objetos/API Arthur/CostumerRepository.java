package br.poo.apinewbank.repository;

import java.util.ArrayList;
import java.util.List;

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

}
