# 🖼️ Fractol - Exploração de Fractais em MiniLibX (42 School)

[](https://github.com/arthur-menezes202/Fratol---school-42)
[](https://en.wikipedia.org/wiki/Fractal)
[](https://en.wikipedia.org/wiki/Julia_set)
[](https://www.google.com/search?q=%5Bhttps://en.wikipedia.org/wiki/Mandelbrot_set%5D\(https://en.wikipedia.org/wiki/Mandelbrot_set\))
[](https://www.google.com/search?q=%5Bhttps://www.42sp.org.br/%5D\(https://www.42sp.org.br/\))

## 📝 Visão Geral do Projeto

**Fractol** é um projeto que consiste na criação de um programa para gerar e visualizar diferentes tipos de fractais, como o Conjunto de Mandelbrot e o Conjunto de Julia, utilizando a biblioteca gráfica **MiniLibX**.

O desafio reside em calcular e renderizar imagens complexas baseadas em iterações de números complexos, além de implementar interatividade para explorar essas fascinantes estruturas matemáticas.

## 🎯 Objetivo de Aprendizagem

O desenvolvimento do Frac'tal proporcionou uma imersão nos seguintes conceitos:

  * **Computação Gráfica Básica:** Entendimento dos fundamentos de rasterização e projeção de pixels em uma janela, utilizando a `MiniLibX`.
  * **Números Complexos:** Aplicação prática de operações com números complexos para o cálculo iterativo dos fractais.
  * **Interatividade:** Implementação de eventos de teclado e mouse para permitir a navegação e exploração dos fractais.

## ✨ Bônus Implementado: Zoom Interativo com o Mouse

Esta implementação inclui uma parte do bônus, que permite a **interação com o fractal através do mouse**:

  * **Zoom Pelo Mouse:** A capacidade de aproximar (zoom in) e afastar (zoom out) o fractal utilizando a **roda de rolagem do mouse**. O ponto de foco do zoom é dinamicamente ajustado para a **posição do ponteiro do mouse**, permitindo uma exploração intuitiva de regiões específicas do fractal.

## 🌈 Fractais Suportados

O programa é capaz de gerar e visualizar os seguintes fractais:

  * **Conjunto de Mandelbrot:** O fractal mais famoso, gerado pela iteração da função `z = z² + c`, onde `c` é o ponto no plano complexo e `z` começa em 0.
  * **Conjunto de Julia:** Uma família de fractais relacionados ao Mandelbrot, gerados pela mesma função `z = z² + c`, mas com `c` fixo e `z` variando sobre o plano complexo.

## ⚙️ Instalação e Uso

### Dependências

O projeto requer a biblioteca gráfica **MiniLibX**, que é padrão na 42 School.

### Compilação

Para compilar o executável `frac_tal`, utilize o `make`:

```bash
git clone https://github.com/arthur-menezes202/Fratol---school-42.git
cd Fratol---school-42
make
```

### Execução

O programa pode ser executado passando o nome do fractal desejado como argumento.

**Exemplos:**

```bash
# Para gerar o Conjunto de Mandelbrot
./fractol Mandelbrot

# Para gerar o Conjunto de Julia
./fractol Julia 0.285 0.01
```

**Interação:**

  * **Roda do Mouse:** Use a roda de rolagem para **zoom in/out**, com o centro do zoom na posição atual do ponteiro do mouse.
  * **`ESC`:** Pressione a tecla `ESC` para sair do programa.

## 🧑‍💻 Autor

| [](https://www.google.com/search?q=https://github.com/arthur-menezes202) | **Arthur Menezes** |
| :---: | :--- |
| | **Perfil GitHub:** [@arthur-menezes202](https://www.google.com/search?q=https://github.com/arthur-menezes202) |
| | **School 42:** armeneze
