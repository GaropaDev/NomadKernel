# Nomad Kernel

Projeto de Kernel desenvolvido (Durante a quarentena da pandeimia) para fins educacionais.

## Requisitos
```
sudo apt install nasm gcc -y
```

## Como utilizar

Execute o compile.sh, o script criará as pastas build e bin, o kernel será armazenado em build, logo, copie ele e jogue para dentro de /boot/

Com esse procedimento realizado, falta vincular o kernel a uma opção no grub, veja a baixo o codigo que deverá ser inserido no /boot/grub/grub.cfg

* Caso utilize o grub
``` bash
title myKernel
    root (hd0,0)
    kernel /boot/kernel-701 ro
```
* Caso utilize o grub 2.0

``` bash
menuentry 'Nomad kernel' {
	set root='hd0,msdos1'
	multiboot /boot/Nomad-Kernel ro
}
```

## Referencias
- Imprimindo na tela:
https://arjunsreedharan.org/post/82710718100/kernels-101-lets-write-a-kernel

- Capturando teclado:
https://arjunsreedharan.org/post/99370248137/kernels-201-lets-write-a-kernel-with-keyboard

## Doação
Caso queira doar para contribuir com as canecas de cafe investidas no projeto.

