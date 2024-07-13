project('seu_projeto', 'c', default_options : ['c_std=c99'])

subdir('clients/')
subdir('routes/')

executable('main', 'main.c',
    link_with : [routes_dep, clients_dep],
)