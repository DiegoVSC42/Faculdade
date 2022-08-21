package br.poo.apinewbank.controller;

import br.poo.apinewbank.service.CostumerService;
import br.poo.apinewbank.dto.CostumerDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class NewBankController {


    CostumerService service = new CostumerService();

    @GetMapping("/costumers")
    public List<CostumerDTO> getCostumers(){
        List<CostumerDTO> dtos = service.getCostumers();
        return dtos;
    }
}
