--CREATE DATABASE BD2

USE BD2
GO

CREATE TABLE Jardins (
  ID_Jardins                 int IDENTITY NOT NULL,
  Nome                       VARCHAR(MAX) NOT NULL,
  Nome_Alternativo           VARCHAR(MAX) NOT NULL,
  PRIMARY KEY (ID_Jardins));

CREATE TABLE Cidades (
  ID_Cidades                 int IDENTITY NOT NULL,
  Nome                       VARCHAR(MAX) NOT NULL,
  Area                       FLOAT(20) NOT NULL, 
  Localizacao_Continente     VARCHAR(MAX) NOT NULL,
  Localizacao_Pais           VARCHAR(MAX) NOT NULL,
  PRIMARY KEY (ID_Cidades)); 

  CREATE TABLE Edificios (
  Codigo_Edificio            int IDENTITY NOT NULL,
  Area_Construida            VARCHAR(MAX) NOT NULL,
  Tipologia                  VARCHAR(MAX) NOT NULL,
  PRIMARY KEY (Codigo_Edificio));

  CREATE TABLE Funcionarios (
  ID_Funcionarios            int IDENTITY NOT NULL,
  Nome                       VARCHAR(MAX) NOT NULL,
  Contacto                   integer NOT NULL,
  PRIMARY KEY (ID_Funcionarios));         

  CREATE TABLE Jardineiros (
  ID_Jardineiros             int IDENTITY NOT NULL,
  Nome                       VARCHAR(MAX) NOT NULL,
  Apelido                    VARCHAR(MAX) NOT NULL,
  Contactos                  INTEGER NOT NULL,
  Total_Horas                INTEGER NOT NULL,
  Endereço_Morada            VARCHAR(MAX) NOT NULL,
  Endereço_Código_Postal     VARCHAR(MAX) NOT NULL,
  Endereço_Localidade        VARCHAR(MAX) NOT NULL,
  PRIMARY KEY (ID_Jardineiros));  

CREATE TABLE Quadro ( 
  IDQ                         INTEGER NOT NULL,
  Anos_Serviço               VARCHAR(MAX) NOT NULL,
  Escalao                    VARCHAR(MAX) NOT NULL, 
  Contacto                   INTEGER NOT NULL,
  PRIMARY KEY(IDQ),
  FOREIGN KEY(IDQ) REFERENCES Funcionarios(ID_Funcionarios)
  );


  CREATE TABLE Temporario ( 
  IDT                        INTEGER NOT NULL,
  Seguro                     VARCHAR(MAX) NOT NULL,
  Nome                       VARCHAR(MAX) NOT NULL, 
  Contacto                   INTEGER NOT NULL,
 );

  CREATE TABLE Conter (
ID_Jardins                   INTEGER NOT NULL,
ID_Cidades                   INTEGER NOT NULL,
PRIMARY KEY(ID_Jardins,ID_Cidades),
FOREIGN KEY(ID_Jardins) REFERENCES Jardins (ID_Jardins),
FOREIGN KEY(ID_Cidades) REFERENCES Cidades (ID_Cidades))

CREATE TABLE Contratar_Func(
ID_Funcionarios              INTEGER NOT NULL,
ID_Cidades                   INTEGER NOT NULL,
Data_Contratar               DATE NOT NULL,
Preco                        float(20) NOT NULL,
PRIMARY KEY(ID_Funcionarios,ID_Cidades,Data_Contratar),
FOREIGN KEY(ID_Funcionarios) REFERENCES Funcionarios (ID_Funcionarios),
FOREIGN KEY(ID_Cidades) REFERENCES Cidades (ID_Cidades))

CREATE TABLE Possuir(
Codigo_Edificio              INTEGER NOT NULL,
ID_Cidades                   INTEGER NOT NULL,
Data_Possuir                 DATE NOT NULL, 
Valor_Possuir                float NOT NULL,
Data_Fim                     DATE NOT NULL,
PRIMARY KEY(Codigo_Edificio,ID_Cidades, Data_Possuir),
FOREIGN KEY(Codigo_Edificio ) REFERENCES Edificios   (Codigo_Edificio ),
FOREIGN KEY(ID_Cidades) REFERENCES Cidades (ID_Cidades))



CREATE TABLE Manutencao(
ID_Jardins              INTEGER NOT NULL,
ID_Jardineiros          INTEGER NOT NULL,
Data_Inicio_Man         DATE NOT NULL,
Data_Fim                DATE NOT NULL,
PRIMARY KEY(ID_Jardins,ID_Jardineiros,Data_Inicio_Man),
FOREIGN KEY(ID_Jardins) REFERENCES Jardins (ID_Jardins),
FOREIGN KEY(ID_Jardineiros) REFERENCES Jardineiros (ID_Jardineiros))


CREATE TABLE Responsaveis(
Codigo_Edificio         int IDENTITY NOT NULL,
Horas_Extra             INTEGER NOT NULL,
FOREIGN KEY(Codigo_Edificio) REFERENCES Edificios (Codigo_Edificio))


CREATE TABLE Contratar_Jard(
IDQ						INTEGER NOT NULL,
ID_Jardineiros          int IDENTITY NOT NULL,
Data_                    DATE NOT NULL,
Salario                 INTEGER NOT NULL,
PRIMARY KEY(ID_Jardineiros, IDQ),
FOREIGN KEY(ID_Jardineiros) REFERENCES Jardineiros (ID_Jardineiros),
FOREIGN KEY(IDQ) REFERENCES Quadro(IDQ)
)


-----------------------------

--1 Insira, pelo menos, 3 registos em cada tabela.


INSERT INTO Jardins(ID_Jardins, Nome, Nome_Alternativo)
VALUES (12345, 'Jardim do Morro', 'Jardim Morro')
INSERT INTO Jardins(ID_Jardins, Nome, Nome_Alternativo)
VALUES (12346, 'Jardim da Carreira', 'Jardim Bar')
INSERT INTO Jardins(ID_Jardins, Nome, Nome_Alternativo)
VALUES (54321, 'Jardins do Palácio de Cristal', 'Jardins do Palacio')


INSERT INTO Cidades(ID_Cidades, Nome, Area, Localizacao_Continente, Localizacao_Pais)
VALUES (62371, 'Paris', 105.4, 'Europa', 'França')
INSERT INTO Cidades(ID_Cidades, Nome, Area, Localizacao_Continente, Localizacao_Pais)
VALUES (23513, 'Toquio', 2194, 'Asia', 'Japão')
INSERT INTO Cidades(ID_Cidades, Nome, Area, Localizacao_Continente, Localizacao_Pais)
VALUES (12371, 'Lisboa', 100, 'Europa', 'Portugal')


INSERT INTO Edificios(Codigo_Edificio, Area_Construida, Tipologia)
VALUES (1252, 20, 'Habitacional')
INSERT INTO Edificios(Codigo_Edificio, Area_Construida, Tipologia)
VALUES (1324, 56, 'Hospitalar')
INSERT INTO Edificios(Codigo_Edificio, Area_Construida, Tipologia)
VALUES (6910, 104, 'Comercial')


INSERT INTO Funcionarios(ID_Funcionarios, Nome, Contacto)
VALUES (103, 'Guilherme Andrade', '937801245')
INSERT INTO Funcionarios(ID_Funcionarios, Nome, Contacto)
VALUES (703, 'Cristiano Ronaldo', '961718291')
INSERT INTO Funcionarios(ID_Funcionarios, Nome, Contacto)
VALUES (076, 'Andre Almeida', '911117891')


INSERT INTO Jardineiros(ID_Jardineiros,  Nome, Apelido , Contactos, Total_Horas, Endereço_Morada, Endereço_Código_Postal, Endereço_Localidade)
VALUES (1231, 'Jose', 'Fonte', 923137129, 27, 'Rua Ramiro Ferrao', '2809-001', 'Almada')
INSERT INTO Jardineiros(ID_Jardineiros,  Nome, Apelido , Contactos, Total_Horas, Endereço_Morada, Endereço_Código_Postal, Endereço_Localidade)
VALUES (9201, 'João', 'Alberto', 914768910, 54, 'Rua Infante Dom Henrique', '6301-861', 'Guarda')
INSERT INTO Jardineiros(ID_Jardineiros,  Nome, Apelido , Contactos, Total_Horas, Endereço_Morada, Endereço_Código_Postal, Endereço_Localidade)
VALUES (7261, 'Alberto', 'Caeiro', 962078918, 47, 'Rua da Mesura', '3044-519', 'Cernache')


INSERT INTO Quadro(Anos_Serviço, Escalao, Contacto)
VALUES (27, 'A', 910000002)
INSERT INTO Quadro(Anos_Serviço, Escalao, Contacto)
VALUES (3, 'B', 934777777)
INSERT INTO Quadro(Anos_Serviço, Escalao, Contacto)
VALUES (45, 'A', 911111111)


INSERT INTO Temporario(Seguro, Nome, Contacto)
VALUES ('Fidelidade', 'Joao Barbosa', 922222222)
INSERT INTO Temporario(Seguro, Nome, Contacto)
VALUES ('Mapfre', 'Bernardo Meneses', 912323434)
INSERT INTO Temporario(Seguro, Nome, Contacto)
VALUES ('Tranquilidade', 'Jose Fonte', 912121212)


INSERT INTO Conter(ID_Jardins, ID_Cidades)
VALUES (12252, 73212)
INSERT INTO Conter(ID_Jardins, ID_Cidades)
VALUES (71252, 91292)
INSERT INTO Conter(ID_Jardins, ID_Cidades)
VALUES (98516, 15021)


INSERT INTO Contratar_Func(ID_Funcionarios, ID_Cidades, Data_Contratar, Preco)
VALUES (809, 89812, '17-02-2009', 150000)
INSERT INTO Contratar_Func(ID_Funcionarios, ID_Cidades, Data_Contratar, Preco)
VALUES (762, 17283, '09-11-2021', 20000)
INSERT INTO Contratar_Func(ID_Funcionarios, ID_Cidades, Data_Contratar, Preco)
VALUES (105, 90901, '17-09-2016', 300000)


INSERT INTO Possuir(Codigo_Edificio, ID_Cidades, Data_Possuir, Valor_Possuir, Data_Fim)
VALUES (5455, 77777, '17-09-2022', 1500, '20-06-2025')
INSERT INTO Possuir(Codigo_Edificio, ID_Cidades, Data_Possuir, Valor_Possuir, Data_Fim)
VALUES (1234, 66666, '11-03-2011', 120000, '11-03-2021')
INSERT INTO Possuir(Codigo_Edificio, ID_Cidades, Data_Possuir, Valor_Possuir, Data_Fim)
VALUES (4321, 55555, '15-05-2019', 135000, '15-08-2019')


INSERT INTO Manutencao(ID_Jardins, ID_Jardineiros, Data_Inicio_Man, Data_Fim)
VALUES (52734, 3214, '7-11-2005', '11-7-2015')
INSERT INTO Manutencao(ID_Jardins, ID_Jardineiros, Data_Inicio_Man, Data_Fim)
VALUES (98252, 1071, '11-8-2014', '5-7-2012')
INSERT INTO Manutencao(ID_Jardins, ID_Jardineiros, Data_Inicio_Man, Data_Fim)
VALUES (11114, 1111, '1-11-2002', '11-1-2021')


INSERT INTO Responsaveis(Codigo_Edificio, Horas_Extra)
VALUES (7777, 123)
INSERT INTO Responsaveis(Codigo_Edificio, Horas_Extra)
VALUES (1224, 211)
INSERT INTO Responsaveis(Codigo_Edificio, Horas_Extra)
VALUES (9123, 713)


INSERT INTO Contratar_Jard(ID_Jardineiros, Data_, Salario)
VALUES (1234, '31-01-2007', 20000)
INSERT INTO Contratar_Jard(ID_Jardineiros, Data_, Salario)
VALUES (7123, '31-03-2017', 18000)
INSERT INTO Contratar_Jard(ID_Jardineiros, Data_, Salario)
VALUES (9013, '13-11-2014', 25000)


--2.1 Qual o 1.º jardineiro contratado? [Jardineiro (Nome), Funcionário (Nome), Data, Salário]

Select Top 1 data_, Jardineiros.Nome, Funcionarios.Nome, Contratar_Jard.Salario
from Jardineiros, Funcionarios, Contratar_Jard
where Jardineiros.Id_jardineiros = Contratar_Jard.Id_jardineiros
Order By data_ ASC


--2.2 Quantos jardineiros foram contratados por cada funcionário? [Funcionário (Nome), N_Jardineiros]

SELECT F.Nome, COUNT(*) AS N_Jardineiros
FROM Funcionarios F, Contratar_Jard CJ, Quadro Q, Jardineiros J
WHERE F.Nome = Q.IDQ
AND Q.IDQ = CJ.IDQ
AND J.ID_Jardineiros = CJ.ID_Jardineiros
GROUP BY J.Nome


--2.3 Qual a cidade com mais jardins? [Cidade (Nome), (Quantidade)]

SELECT TOP 1 C.Nome, COUNT(DISTINCT J.ID_Jardins) AS Quantidade
FROM Cidades C, Jardins J, Conter CO
WHERE C.ID_Cidades = Co.ID_Cidades
AND Co.ID_Jardins = J.ID_Jardins
ORDER BY Quantidade ASC


--2.4. Qual a cidade que mais funcionários contratou nos últimos 30 dias? [Cidade (Nome), Número de Funcionários]

SELECT TOP 1 C.Nome, COUNT(DISTINCT F.ID_Funcionarios) AS Num_Func
FROM Cidades C, Contratar_Func CF, Funcionarios F
WHERE DATEDIFF(day, CF.Data_Contratar, getdate())<30
AND CF.ID_Funcionarios = F.ID_Funcionarios
AND CF.ID_Cidades = C.ID_Cidades
ORDER BY Num_Func ASC;


--2.5. Quais os Jardins que não têm nenhum jardineiro na manutenção? [Jardins(Nome)]

SELECT J.Nome
FROM Jardins J, Manutencao M, Jardineiros Jar
WHERE J.ID_Jardins = M.ID_Jardins
AND M.ID_Jardineiros NOT IN (Jar.ID_Jardineiros)


--2.6. Quais os Funcionários Temporários a trabalhar em cada Edifício? Ordene-os alfabeticamente. [Funcionários (Nome), Edifício (Código)]

SELECT T.Nome, E.Codigo_Edificio, F.ID_Funcionarios, COUNT (DISTINCT F.ID_Funcionarios) AS Num_Funcionarios
FROM Temporario T, Edificios E, Funcionarios F
WHERE (T.Nome=E.Codigo_Edificio)
GROUP BY T.Nome



--2.7. Qual o total gasto em contratações de Funcionários por cada cidade em 2022? [Cidade (Nome), TotalGasto]

SELECT TOP 1 C.Nome, COUNT (DISTINCT CF.Preco) as PrecoTot
FROM Cidades C, Contratar_Func CF
WHERE C.ID_Cidades = CF.ID_Cidades
ORDER by C.Nome



--3. Assumindo que para os jardineiros as horas extra são pagas a 10€/h, crie um procedimento que para um dado mês atualize o TotalHoras na tabela Jardineiro e 
--apresente uma tabela com os ID, nome e apelidos dos jardineiros e o total que cada um recebe nesse mês. O procedimento deve devolver o total da despesa com os jardineiros

CREATE PROCEDURE despesaJardineiros @Total_Horas_Jardineiros INTEGER

    DECLARE @despesa MONEY;
    DECLARE @Horas_Extra INTEGER;
	DECLARE @ID_Jardineiro INTEGER;

    SET @despesa = (SELECT Contratar_Jard.Salario
                    FROM Contratar_Jard
                    WHERE ID_Jardineiros = @ID_Jardineiros);

    EXECUTE @despesa = getDespesa @Contratar_Jard.Salario;

    UPDATE @Jardineiros.TotalHoras WHERE Jardineiros;

    PRINT @ID_Jardineiros, @Jardineiros.Nome, @Jardineiros.Apelido @Contratar_Jard.Salario;

    RETURN @despesa


--4. Crie um trigger que apenas deixe inserir um novo registo no relacionamento Contratar -> Funcionário se o ID do indivíduo a contratar ainda não constar dos Funcionários

CREATE TRIGGER InserirRegisto
ON Contratar_Func
{
INSTEAD OF INSERT
AS
IF (select Funcionarios.ID_Funcionarios from Funcionarios where Funcionarios.ID_Funcionarios IS NOT NULL)
end if;
}



