project('seu_projeto', 'c', default_options : ['c_std=c99'])

subdir('backend/clients/')
subdir('backend/routes/')
subdir('backend/pedidos/')
subdir('backend/cria_libera/')
subdir('backend/exibir/')
subdir('backend/menu/')

executable('main', 'main.c',
    link_with : [routes_dep,cliente_dep, pedidos_dep,menu_dep,cria_libera_dep,exibir_dep],
)