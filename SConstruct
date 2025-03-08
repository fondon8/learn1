import os

# to use run => scons src=learn1

env = Environment()
env['ENV']['PATH'] = ['E:/fondon/dmc/bin']

cc = Builder(action='dmc -c -I./include -I../../dmc/stlport/stlport -v1 $SOURCE')
link = Builder(action='link $SOURCE,,,advapi32+lib\\pdcurses/NOIGNORECASE /DETAILEDMAP /INFORMATION')

env['BUILDERS']['CC'] = cc
env['BUILDERS']['LINK'] = link

src = ARGUMENTS.get('src')

if src is not None:
# python string substitution
  print("src=%s" % src)
  print("cpp file is {}.cpp".format(src))
  print("obj file is {SOURCE}.obj".format(SOURCE=src))
  print(f"and so exe file is {src}.exe")

# env.Alias('learn1', [env.CC('learn1.obj', 'learn1.cpp'), env.LINK('learn1.exe', 'learn1.obj')])
  env.Alias('learn', [env.CC(f'{src}.obj', f'{src}.cpp'), env.LINK(f'{src}.exe', f'{src}.obj')])

# env.Alias('print_note', print('To run: scons src=learn1'))
# Default('print_note')

if env.GetOption('clean'):
  dir_name = "."
  files = os.listdir(dir_name)
  for item in files:
      if item.endswith(".exe") or item.endswith(".obj") or item.endswith(".map"):
          os.remove(os.path.join(dir_name, item))
