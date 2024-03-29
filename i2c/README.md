# I2C

## 関数
- [MasterTransmit](function/README.md#mastertransmit)
  - [i2cMasterTransmit](function/README.md#i2cmastertransmit)
  - [i2cMasterTransmit_IT](function/README.md#i2cmastertransmit_it)
  - [i2cMasterTransmit_DMA](function/README.md#i2cmastertransmit_dma)
- [MasterReceive](function/README.md#masterreceive)
  - [i2cMasterReceive](function/README.md#i2cmasterreceive)
  - [i2cMasterReceive_IT](function/README.md#i2cmasterreceive_it)
  - [i2cMasterReceive_DMA](function/README.md#i2cmasterreceive_dma)
- [SlaveTransmit](function/README.md#slavetransmit)
  - [i2cSlaveTransmit](function/README.md#i2cslavetransmit)
  - [i2cSlaveTransmit_IT](function/README.md#i2cslavetransmit_it)
  - [i2cSlaveTransmit_DMA](function/README.md#i2cslavetransmit_dma)
- [SlaveReceive](function/README.md#slavereceive)
  - [i2cSlaveReceive](function/README.md#i2cslavereceive)
  - [i2cSlaveReceive_IT](function/README.md#i2cslavereceive_it)
  - [i2cSlaveReceive_DMA](function/README.md#i2cslavereceive_dma)
- [Callback](function/README.md#callback)
  - [setI2CMasterTxCallback](function/README.md#seti2cmastertxcallback)
  - [setI2CMasterRxCallback](function/README.md#seti2cmasterrxcallback)
  - [setI2CSlaveTxCallback](function/README.md#seti2cslavetxcallback)
  - [setI2CSlaveRxCallback](function/README.md#seti2cslaverxcallback)
  - [setI2CErrorCallback](function/README.md#seti2cerrorcallback)

## クラス
- [I2C_Master](class/I2C_Master.md)
  - [CubeMX](class/I2C_Master.md#cubemx)
  - [クラステンプレート](class/I2C_Master.md#クラステンプレート)
  - [コンストラクタ](class/I2C_Master.md#コンストラクタ)
    - [I2C_Master(I2C_HandleTypeDef)](class/I2C_Master.md#i2c_masteri2c_masteri2c_handletypedef)
  - [関数](class/I2C_Master.md#関数)
    - [init()](class/I2C_Master.md#i2c_masterinit)
    - [transmit(uint8_t, T, uint32_t)](class/I2C_Master.md#i2c_mastertransmituint8_t-t-uint32_t)
    - [receive(uint8_t, T, uint32_t)](class/I2C_Master.md#i2c_masterreceiveuint8_t-t-uint32_t)
- [I2C_Master_IT](class/I2C_Master_IT.md)
  - [CubeMX](class/I2C_Master_IT.md#cubemx)
  - [クラステンプレート](class/I2C_Master_IT.md#クラステンプレート)
  - [コンストラクタ](class/I2C_Master_IT.md#コンストラクタ)
    - [I2C_Master_IT(I2C_HandleTypeDef)](class/I2C_Master_IT.md#i2c_master_iti2c_master_iti2c_handletypedef)
  - [関数](class/I2C_Master_IT.md#関数)
    - [init()](class/I2C_Master_IT.md#i2c_master_itinit)
    - [transmit(uint8_t, T)](class/I2C_Master_IT.md#i2c_master_ittransmituint8_t-t)
    - [receive(uint8_t, T)](class/I2C_Master_IT.md#i2c_master_itreceiveuint8_t-t)
- [I2C_Master_DMA](class/I2C_Master_DMA.md)
  - [CubeMX](class/I2C_Master_DMA.md#cubemx)
  - [クラステンプレート](class/I2C_Master_DMA.md#クラステンプレート)
  - [コンストラクタ](class/I2C_Master_DMA.md#コンストラクタ)
    - [I2C_Master_DMA(I2C_HandleTypeDef, uint8_t, T)](class/I2C_Master_DMA.md#i2c_master_dmai2c_master_dmai2c_handletypedef-uint8_t-t)
  - [関数](class/I2C_Master_DMA.md#関数)
    - [init()](class/I2C_Master_DMA.md#i2c_master_dmainit)
    - [startTransmit()](class/I2C_Master_DMA.md#i2c_master_dmastarttransmit)
    - [startReceive()](class/I2C_Master_DMA.md#i2c_master_dmastartreceive)
    - [setTxCallback(std::function<void()>)](class/I2C_Master_DMA.md#i2c_master_dmasettxcallbackstdfunctionvoid)
    - [setRxCallback(std::function<void()>)](class/I2C_Master_DMA.md#i2c_master_dmasetrxcallbackstdfunctionvoid)
    - [setErrorCallback(std::function<void()>)](class/I2C_Master_DMA.md#i2c_master_dmaseterrorcallbackstdfunctionvoid)
- [I2C_Slave](class/I2C_Slave.md)
  - [CubeMX](class/I2C_Slave.md#cubemx)
  - [クラステンプレート](class/I2C_Slave.md#クラステンプレート)
  - [コンストラクタ](class/I2C_Slave.md#コンストラクタ)
    - [I2C_Slave(I2C_HandleTypeDef uint8_t)](class/I2C_Slave.md#i2c_slavei2c_slavei2c_handletypedef-uint8_t)
  - [関数](class/I2C_Slave.md#関数)
    - [init()](class/I2C_Slave.md#i2c_slaveinit)
    - [init(uint8_t)](class/I2C_Slave.md#i2c_slaveinituint8_t)
    - [transmit(T, uint32_t)](class/I2C_Slave.md#i2c_slavetransmitt-uint32_t)
    - [receive(T, uint32_t)](class/I2C_Slave.md#i2c_slavereceivet-uint32_t)
- [I2C_Slave_IT](class/I2C_Slave_IT.md)
  - [CubeMX](class/I2C_Slave_IT.md#cubemx)
  - [クラステンプレート](class/I2C_Slave_IT.md#クラステンプレート)
  - [コンストラクタ](class/I2C_Slave_IT.md#コンストラクタ)
    - [I2C_Slave_IT(I2C_HandleTypeDef, uint8_t)](class/I2C_Slave_IT.md#i2c_slave_iti2c_slave_iti2c_handletypedef-uint8_t)
  - [関数](class/I2C_Slave_IT.md#関数)
    - [init()](class/I2C_Slave_IT.md#i2c_slave_itinit)
    - [init(uint8_t)](class/I2C_Slave_IT.md#i2c_slave_itinituint8_t)
    - [transmit(T)](class/I2C_Slave_IT.md#i2c_slave_ittransmitt)
    - [receive(T)](class/I2C_Slave_IT.md#i2c_slave_itreceivet)
    - [setTxCallback(std::function<void()>)](class/I2C_Slave_IT.md#i2c_slave_itsettxcallbackstdfunctionvoid)
    - [setRxCallback(std::function<void()>)](class/I2C_Slave_IT.md#i2c_slave_itsetrxcallbackstdfunctionvoid)
    - [setErrorCallback(std::function<void()>)](class/I2C_Slave_IT.md#i2c_slave_itseterrorcallbackstdfunctionvoid)
- [I2C_Slave_DMA](class/I2C_Slave_DMA.md)
  - [CubeMX](class/I2C_Slave_DMA.md#cubemx)
  - [クラステンプレート](class/I2C_Slave_DMA.md#クラステンプレート)
  - [コンストラクタ](class/I2C_Slave_DMA.md#コンストラクタ)
    - [I2C_Slave_DMA(I2C_HandleTypeDef, T, uint8_t)](class/I2C_Slave_DMA.md#i2c_slave_dmai2c_slave_dmai2c_handletypedef-t-uint8_t)
  - [関数](class/I2C_Slave_DMA.md#関数)
    - [init()](class/I2C_Slave_DMA.md#i2c_slave_dmainit)
    - [init(uint8_t)](class/I2C_Slave_DMA.md#i2c_slave_dmainituint8_t)
    - [startTransmit()](class/I2C_Slave_DMA.md#i2c_slave_dmastarttransmit)
    - [startReceive()](class/I2C_Slave_DMA.md#i2c_slave_dmastartreceive)
    - [setTxCallback(std::function<void()>)](class/I2C_Slave_DMA.md#i2c_slave_dmasettxcallbackstdfunctionvoid)
    - [setRxCallback(std::function<void()>)](class/I2C_Slave_DMA.md#i2c_slave_dmasetrxcallbackstdfunctionvoid)
    - [setErrorCallback(std::function<void()>)](class/I2C_Slave_DMA.md#i2c_slave_dmaseterrorcallbackstdfunctionvoid)

[<< 戻る](../README.md)