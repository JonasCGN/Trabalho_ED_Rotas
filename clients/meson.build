# Adiciona a biblioteca 'functions' que será usada por outros componentes
clients_sources = [
  'cliente.c'
]

clients_dep = static_library('clients', clients_sources, 
    install: true,
    install_dir: 'lib'
)

install_headers('cliente.h', subdir: 'clients')