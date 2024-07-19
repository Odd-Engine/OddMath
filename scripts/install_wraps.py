import subprocess
from threading import Thread
from os import path, mkdir
from pathlib import Path

PROJECT_ROOT = Path(path.dirname(__file__)).parent
SUBPROJECTS_PATH = path.join(PROJECT_ROOT, "subprojects")

if not path.exists(SUBPROJECTS_PATH):
    mkdir(SUBPROJECTS_PATH)

def get_wrap(wrap):
    subprocess.Popen(["meson", "wrap", "install", wrap], cwd=PROJECT_ROOT).wait()

wraps = [
    "gtest"
]

threads: list[Thread] = []
for wrap in wraps:
    threads.append(Thread(target=get_wrap, args=(wrap,)))
    threads[-1].start()