# Installation de Frama-C

## Installer OPAM

```sh
sudo apt install opam
```

## Initialiser OPAM

```sh
opam init --compiler 4.14.1
```

## Mettre à jour l'environnement shell

```sh
eval $(opam env)
```

-   Je vous conseille d'ajouter cette commande à votre fichier `.bashrc`.

## Installer Frama-C et le solveurs qui vont avec

```sh
opam install alt-ergo z3 why3 frama-c
```

## Mettre à jour l'environnement shell

```sh
eval $(opam env)
```

## Configurer Why3 automatiquement

```sh
why3 config detect
```
