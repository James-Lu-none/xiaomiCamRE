# this is a project that performs reverse engineering of xiaomi security camera

## requirement

- putty
- binwalk
- 

## datasheet for chips

- High-Integrated IP Camera SoC Processor <https://linux-chenxing.org/infinity3/msc313e_pb_v03.pdf>
- flash <https://www.winbond.com/resource-files/w25q128jv%20revf%2003272018%20plus.pdf>

## extract data

1. /data in unblob contains /data/input and /data/output

```bash
# docker run -v [input file]:/data/input/[file name] unblob /data/input/[file name]
docker run -v $(pwd)/generatedFiles/03.bin:/data/input/01 unblob /data/input/01
```

2. copy output extracted data to local

```bash
docker cp nice_black:/data/output/ ~/projects/cProject/xiaomiCamRE/generatedFiles/01
```