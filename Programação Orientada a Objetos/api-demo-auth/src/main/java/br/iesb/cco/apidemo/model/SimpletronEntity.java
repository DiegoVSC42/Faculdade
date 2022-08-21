package br.iesb.cco.apidemo.model;

import java.util.Date;
import java.util.List;

/**
 * Simpletron Version 1.0
 *
 *  Registers:
 *      IP
 *      ACC
 *
 *  Instructions:
 *      ADD
 *      LOAD
 *      STORE
 *      WRITE
 *      SUB
 *      READ
 */
public class SimpletronEntity {
    private long id;
    private String name;
    private String description;
    private String model;
    private String brand;
    private float price;
    private int inputBytesCount;
    private int memory;
    private String memoryUnit;
    private List<String> registers;
    private List<String> instructions;
    private Date creationDate;
    private Date updateDate;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public int getInputBytesCount() {
        return inputBytesCount;
    }

    public void setInputBytesCount(int inputBytesCount) {
        this.inputBytesCount = inputBytesCount;
    }

    public int getMemory() {
        return memory;
    }

    public void setMemory(int memory) {
        this.memory = memory;
    }

    public String getMemoryUnit() {
        return memoryUnit;
    }

    public void setMemoryUnit(String memoryUnit) {
        this.memoryUnit = memoryUnit;
    }

    public List<String> getRegisters() {
        return registers;
    }

    public void setRegisters(List<String> registers) {
        this.registers = registers;
    }

    public List<String> getInstructions() {
        return instructions;
    }

    public void setInstructions(List<String> instructions) {
        this.instructions = instructions;
    }

    public Date getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(Date creationDate) {
        this.creationDate = creationDate;
    }

    public Date getUpdateDate() {
        return updateDate;
    }

    public void setUpdateDate(Date updateDate) {
        this.updateDate = updateDate;
    }
}