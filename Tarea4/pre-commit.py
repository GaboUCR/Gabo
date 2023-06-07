import subprocess
import sys


def main():
    """Ejecuta flake8 y aborta el commit si flake8 encuentra problemas."""
    result = subprocess.run([sys.executable, '-m', 'flake8', './Tarea4'],
                            stdout=subprocess.PIPE)

    if result.returncode != 0:
        print(result.stdout.decode('utf-8'))
        return 1
    else:
        print('No se encontraron problemas de estilo.')
        return 0


if __name__ == '__main__':
    sys.exit(main())
