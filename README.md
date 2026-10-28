**Title:** Multiprocessing infrasctructure

**Date:** 10/2026 

**Status:** Accepted 

**Owner:** Dr. Kraemer, Alessandro [sp.kraemer.alessandro@gmail.com](mailto:sp.kraemer.alessandro@gmail.com) 
O CV está disponível e com Direito Autoral ali no CNPq e autorizo para estudar. O repositório no CNPq é por via [https://lattes.cnpq.br](https://lattes.cnpq.br/) e ali marque DOUTOR. 

**Context:** Uma infraestrutura para processamento paralelo, aqui uso em C.

**Decision:** Opta-se pelo software o Linux ali e VMWare ali o Workstation 17... (converta se for cabido). Há uma integração que proponho o para acesso e manutenção o para estudo. Ali no *branch* da máquina virtual incluo o com Linux o Ubuntu Server 26.04 LTS o mais MySQL 8.4.10 e mais ferrramenta, que auxílio por outro meio o em aula etc. Cito aqui usuário mais senha mas sem segurança no momento:

**Updates libraries**
sudo apt-get update
sudo apt-get upgrade

**Installs requerimients**
sudo apt-get install g++ make

**Locate in user dir**
cd ~

**Installs & unpack package**
wget https://download.open-mpi.org/release/open-mpi/v4.1/openmpi-4.1.4.tar.gz
gunzip -c openmpi-4.1.4.tar.gz | tar xf -
cd openmpi-4.1.4

**Installation**
./configure --prefix=/usr/local
make all install
sudo apt-get install openmpi-bin libopenmpi-dev

**An example with 4 processors...**
mpiCC SourceCode.cpp -o first
mpirun -np 4 first

**Consequences:** O utilizador contempla a infraestrutura para migrar e disponha onde for preciso...
