# function I2C

## 目次
- [MasterTransmit](#mastertransmit)
  - [i2cMasterTransmit](#i2cmastertransmit)
  - [i2cMasterTransmit_IT](#i2cmastertransmit_it)
  - [i2cMasterTransmit_DMA](#i2cmastertransmit_dma)
- [MasterReceive](#masterreceive)
  - [i2cMasterReceive](#i2cmasterreceive)
  - [i2cMasterReceive_IT](#i2cmasterreceive_it)
  - [i2cMasterReceive_DMA](#i2cmasterreceive_dma)
- [SlaveTransmit](#slavetransmit)
  - [i2cSlaveTransmit](#i2cslavetransmit)
  - [i2cSlaveTransmit_IT](#i2cslavetransmit_it)
  - [i2cSlaveTransmit_DMA](#i2cslavetransmit_dma)
- [SlaveReceive](#slavereceive)
  - [i2cSlaveReceive](#i2cslavereceive)
  - [i2cSlaveReceive_IT](#i2cslavereceive_it)
  - [i2cSlaveReceive_DMA](#i2cslavereceive_dma)
- [Callback](#callback)
  - [setI2CMasterTxCallback](#seti2cmastertxcallback)
  - [setI2CMasterRxCallback](#seti2cmasterrxcallback)
  - [setI2CSlaveTxCallback](#seti2cslavetxcallback)
  - [setI2CSlaveRxCallback](#seti2cslaverxcallback)
  - [setI2CErrorCallback](#seti2cerrorcallback)

## 関数

### MasterTransmit

##### i2cMasterTransmit
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterTransmit(I2C_HandleTypeDef *hi2c, uint8_t target, const T &data, uint32_t timeout) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterTransmit(I2C_HandleTypeDef &hi2c, uint8_t target, const T &data, uint32_t timeout) noexcept;
> ```
> `HAL_I2C_Master_Transmit` を実行します

##### i2cMasterTransmit_IT
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterTransmit_IT(I2C_HandleTypeDef *hi2c, uint8_t target, const T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterTransmit_IT(I2C_HandleTypeDef &hi2c, uint8_t target, const T &data) noexcept;
> ```
> `HAL_I2C_Master_Transmit_IT` を実行します

##### i2cMasterTransmit_DMA
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterTransmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t target, const T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterTransmit_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, const T &data) noexcept;
> ```
> `HAL_I2C_Master_Transmit_DMA` を実行します

### MasterReceive

##### i2cMasterReceive
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterReceive(I2C_HandleTypeDef *hi2c, uint8_t target, T &data, uint32_t timeout) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterReceive(I2C_HandleTypeDef &hi2c, uint8_t target, T &data, uint32_t timeout) noexcept;
> ```
> `HAL_I2C_Master_Receive` を実行します

##### i2cMasterReceive_IT
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterReceive_IT(I2C_HandleTypeDef *hi2c, uint8_t target, T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterReceive_IT(I2C_HandleTypeDef &hi2c, uint8_t target, T &data) noexcept;
> ```
> `HAL_I2C_Master_Receive_IT` を実行します

##### i2cMasterReceive_DMA
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterReceive_DMA(I2C_HandleTypeDef *hi2c, uint8_t target, T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cMasterReceive_DMA(I2C_HandleTypeDef &hi2c, uint8_t target, T &data) noexcept;
> ```
> `HAL_I2C_Master_Receive_DMA` を実行します

### SlaveTransmit

##### i2cSlaveTransmit
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveTransmit(I2C_HandleTypeDef *hi2c, const T &data, uint32_t timeout) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveTransmit(I2C_HandleTypeDef &hi2c, const T &data, uint32_t timeout) noexcept;
> ```
> `HAL_I2C_Slave_Transmit` を実行します

##### i2cSlaveTransmit_IT
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveTransmit_IT(I2C_HandleTypeDef *hi2c, const T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveTransmit_IT(I2C_HandleTypeDef &hi2c, const T &data) noexcept;
> ```
> `HAL_I2C_Slave_Transmit_IT` を実行します

##### i2cSlaveTransmit_DMA
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveTransmit_DMA(I2C_HandleTypeDef *hi2c, const T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveTransmit_DMA(I2C_HandleTypeDef &hi2c, const T &data) noexcept;
> ```
> `HAL_I2C_Slave_Transmit_DMA` を実行します

### SlaveReceive

##### i2cSlaveReceive
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveReceive(I2C_HandleTypeDef *hi2c, T &data, uint32_t timeout) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveReceive(I2C_HandleTypeDef &hi2c, T &data, uint32_t timeout) noexcept;
> ```
> `HAL_I2C_Slave_Receive` を実行します

##### i2cSlaveReceive_IT
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveReceive_IT(I2C_HandleTypeDef *hi2c, T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveReceive_IT(I2C_HandleTypeDef &hi2c, T &data) noexcept;
> ```
> `HAL_I2C_Slave_Receive_IT` を実行します

##### i2cSlaveReceive_DMA
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveReceive_DMA(I2C_HandleTypeDef *hi2c, T &data) noexcept;
> ```
> ```c++
> template <class T>
> inline HAL_StatusTypeDef i2cSlaveReceive_DMA(I2C_HandleTypeDef &hi2c, T &data) noexcept;
> ```
> `HAL_I2C_Slave_Receive_DMA` を実行します

### Callback

##### setI2CMasterTxCallback
> ```c++
> void setI2CMasterTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
> void setI2CMasterTxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
> ```
> `HAL_I2C_MasterTxCpltCallback` の処理を変更します

##### setI2CMasterRxCallback
> ```c++
> void setI2CMasterRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
> void setI2CMasterRxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
> ```
> `HAL_I2C_MasterRxCpltCallback` の処理を変更します

##### setI2CSlaveTxCallback
> ```c++
> void setI2CSlaveTxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
> void setI2CSlaveTxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
> ```
> `HAL_I2C_SlaveTxCpltCallback` の処理を変更します

##### setI2CSlaveRxCallback
> ```c++
> void setI2CSlaveRxCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
> void setI2CSlaveRxCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
> ```
> `HAL_I2C_SlaveRxCpltCallback` の処理を変更します

##### setI2CErrorCallback
> ```c++
> void setI2CErrorCallback(I2C_HandleTypeDef *hi2c, std::function<void()> function);
> void setI2CErrorCallback(I2C_HandleTypeDef &hi2c, std::function<void()> function);
> ```
> `HAL_I2C_ErrorCallback` の処理を変更します

[<< 戻る](../INDEX.md)