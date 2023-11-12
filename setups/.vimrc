set number
"set relativenumber
syntax enable
set smartindent
set autoindent
"set expandtab
set cindent
set mouse=a
set tabstop=4
set shiftwidth=4
set hlsearch
set incsearch
set cursorline
set ruler
hi LineNr term=italic ctermfg=208 ctermbg=235 gui=italic
set showmode
autocmd FileType python,ruby,perl,sh,c setlocal colorcolumn=80
autocmd BufWritePre * :%s/\s\+$//e
