# CAN_FilterConfig

## 目次
- [関数](#関数)
  - [setFilterFIFOAssignment(uint32_t)](#can_filterconfigsetfilterfifoassignmentuint32_t)
  - [setFilterBank(uint32_t)](#can_filterconfigsetfilterbankuint32_t)
  - [setSlaveStartFilterBank(uint32_t)](#can_filterconfigsetslavestartfilterbankuint32_t)
  - [setIdFilter(...)](#can_filterconfigsetidfilteruint32_t)
  - [setIdMaskFilter(...)](#can_filterconfigsetidmaskfilteruint32_t-uint32_t)
  - [setIdRangeFilter(...)](#can_filterconfigsetidrangefilteruint32_t-uint32_t)
  - [disableFilter()](#can_filterconfigdisablefilter)
  - [get()](#can_filterconfigget)

## 関数
##### CAN_FilterConfig::setFilterFIFOAssignment(uint32_t)
> ```c++
> void setFilterFIFOAssignment(
>     uint32_t value
> );
> ```
> `FilterFIFOAssignment` を設定します

##### CAN_FilterConfig::setFilterBank(uint32_t)
> ```c++
> void setFilterBank(
>     uint32_t value
> );
> ```
> `FilterBank` を設定します

##### CAN_FilterConfig::setSlaveStartFilterBank(uint32_t)
> ```c++
> void setSlaveStartFilterBank(
>     uint32_t value
> );
> ```
> `SlaveStartFilterBank` を設定します

##### CAN_FilterConfig::setIdFilter(...)
> ```c++
> void setIdFilter(uint32_t id1);
> void setIdFilter(uint32_t id1, uint32_t id2);
> void setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3);
> void setIdFilter(uint32_t id1, uint32_t id2, uint32_t id3, uint32_t id4);
> void setIdFilter(CAN_IdentifierType type1, uint32_t id1);
> void setIdFilter(CAN_IdentifierType type1, uint32_t id1, CAN_IdentifierType type2, uint32_t id2);
> ```
> ID リスト形式のフィルタを設定します  
> 標準 ID のみを使う場合は最大 4 件、識別子種別を含める場合は 32bit フィルタで 2 件まで設定できます
> ```c++
> // 例
> filter.setIdFilter(0x100, 0x101);
> filter.setIdFilter(CAN_IdentifierType::Extended, 0x18FF50E5);
> ```

##### CAN_FilterConfig::setIdMaskFilter(...)
> ```c++
> void setIdMaskFilter(uint32_t id1, uint32_t mask1);
> void setIdMaskFilter(uint32_t id1, uint32_t mask1, uint32_t id2, uint32_t mask2);
> void setIdMaskFilter(CAN_IdentifierType type, uint32_t id, uint32_t mask);
> ```
> ID とマスクを使うフィルタを設定します
> ```c++
> // 例
> filter.setIdMaskFilter(0x100, 0x7F0);
> ```

##### CAN_FilterConfig::setIdRangeFilter(...)
> ```c++
> void setIdRangeFilter(uint32_t minId1, uint32_t maxId1);
> void setIdRangeFilter(uint32_t minId1, uint32_t maxId1, uint32_t minId2, uint32_t maxId2);
> void setIdRangeFilter(CAN_IdentifierType type, uint32_t minId, uint32_t maxId);
> ```
> 範囲指定からマスクを計算してフィルタを設定します
> ```c++
> // 例
> filter.setIdRangeFilter(0x100, 0x10F);
> ```

##### CAN_FilterConfig::disableFilter()
> ```c++
> void disableFilter();
> ```
> フィルタを無効化します

##### CAN_FilterConfig::get()
> ```c++
> CAN_FilterTypeDef* get();
> ```
> `HAL_CAN_ConfigFilter()` に渡す設定構造体を返します

[<< 戻る](../README.md)
