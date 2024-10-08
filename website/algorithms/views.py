import subprocess
import urllib.parse
from django.http import HttpResponse
from django.template import loader

try:
    # For Windows
    import build.Debug.cpp_function as cpp_function
except ImportError:
    # For Mac/Linux
    import build.cpp_function as cpp_function


def homePage(request):
    context = {}
    template = loader.get_template('home.html')
    return HttpResponse(template.render(context, request))


def algorithms(request):

    prog_choice = request.GET.get('prog_choice')
    if prog_choice is not None and len(prog_choice) > 0:
        prog_choice = float(prog_choice)
    else:
        prog_choice = 0

    v0 = request.GET.get('V0')
    if v0 is not None and len(v0) > 0:
        v0 = float(v0)
    else:
        v0 = 0

    r = request.GET.get('r')
    if r is not None and len(r) > 0:
        r = float(r)
    else:
        r = 0

    th = request.GET.get('th')
    if th is not None and len(th) > 0:
        th = float(th)
    else:
        th = 0

    c = request.GET.get('c')
    if c is not None and len(c) > 0:
        c = float(c)
    else:
        c = 0

    m = request.GET.get('m')
    if m is not None and len(m) > 0:
        m = float(m)
    else:
        m = 0

    method_choice = request.GET.get('method_choice')
    if method_choice is not None and len(method_choice) > 0:
        method_choice = float(method_choice)
    else:
        method_choice = 0

    L = request.GET.get('L')
    if L is not None and len(L) > 0:
        L = float(L)
    else:
        L = 0

    C = request.GET.get('C')
    if C is not None and len(C) > 0:
        C = float(C)
    else:
        C = 0

    R = request.GET.get('R')
    if R is not None and len(R) > 0:
        R = float(R)
    else:
        R = 0

    initialTime = request.GET.get('initialTime')
    if initialTime is not None and len(initialTime) > 0:
        initialTime = float(initialTime)
    else:
        initialTime = 0

    finalTime = request.GET.get('finalTime')
    if finalTime is not None and len(finalTime) > 0:
        finalTime = float(finalTime)
    else:
        finalTime = 0

    i0 = request.GET.get('i0')
    if i0 is not None and len(i0) > 0:
        i0 = float(i0)
    else:
        i0 = 0

    q0 = request.GET.get('q0')
    if q0 is not None and len(q0) > 0:
        q0 = float(q0)
    else:
        q0 = 0

    n = request.GET.get('n')
    if n is not None and len(n) > 0:
        n = float(n)
    else:
        n = 0

    m1 = request.GET.get('m1')
    if m1 is not None and len(m1) > 0:
        m1 = float(m1)
    else:
        m1 = 0

    m2 = request.GET.get('m2')
    if m2 is not None and len(m2) > 0:
        m2 = float(m2)
    else:
        m2 = 0

    l1 = request.GET.get('l1')
    if l1 is not None and len(l1) > 0:
        l1 = float(l1)
    else:
        l1 = 0

    l2 = request.GET.get('l2')
    if l2 is not None and len(l2) > 0:
        l2 = float(l2)
    else:
        l2 = 0

    o11 = request.GET.get('o11')
    if o11 is not None and len(o11) > 0:
        o11 = float(o11)
    else:
        o11 = 0

    o22 = request.GET.get('o22')
    if o22 is not None and len(o22) > 0:
        o22 = float(o22)
    else:
        o22 = 0

    g = request.GET.get('g')
    if g is not None and len(g) > 0:
        g = float(g)
    else:
        g = 0

    p = request.GET.get('p')
    if p is not None and len(p) > 0:
        p = float(p)
    else:
        p = 0

    mu = request.GET.get('mu')
    if mu is not None and len(mu) > 0:
        mu = float(mu)
    else:
        mu = 0

    x = request.GET.get('x')
    if x is not None and len(x) > 0:
        x = float(x)
    else:
        x = 0

    v0 = request.GET.get('v0')
    if v0 is not None and len(v0) > 0:
        v0 = float(v0)
    else:
        v0 = 0

    q = request.GET.get('q')
    if q is not None and len(q) > 0:
        q = float(q)
    else:
        q = 0

    vx = request.GET.get('vx')
    if vx is not None and len(vx) > 0:
        vx = float(vx)
    else:
        vx = 0

    vy = request.GET.get('vy')
    if vy is not None and len(vy) > 0:
        vy = float(vy)
    else:
        vy = 0

    vz = request.GET.get('vz')
    if vz is not None and len(vz) > 0:
        vz = float(vz)
    else:
        vz = 0

    Ex = request.GET.get('Ex')
    if Ex is not None and len(Ex) > 0:
        Ex = float(Ex)
    else:
        Ex = 0

    Ey = request.GET.get('Ey')
    if Ey is not None and len(Ey) > 0:
        Ey = float(Ey)
    else:
        Ey = 0

    Ez = request.GET.get('Ez')
    if Ez is not None and len(Ez) > 0:
        Ez = float(Ez)
    else:
        Ez = 0

    Bx = request.GET.get('Bx')
    if Bx is not None and len(Bx) > 0:
        Bx = float(Bx)
    else:
        Bx = 0

    By = request.GET.get('By')
    if By is not None and len(By) > 0:
        By = float(By)
    else:
        By = 0

    Bz = request.GET.get('Bz')
    if Bz is not None and len(Bz) > 0:
        Bz = float(Bz)
    else:
        Bz = 0

    sigma = request.GET.get('sigma')
    if sigma is not None and len(sigma) > 0:
        sigma = float(sigma)
    else:
        sigma = 0

    rho = request.GET.get('rho')
    if rho is not None and len(rho) > 0:
        rho = float(rho)
    else:
        rho = 0

    beta = request.GET.get('beta')
    if beta is not None and len(beta) > 0:
        beta = float(beta)
    else:
        beta = 0

    y = request.GET.get('y')
    if y is not None and len(y) > 0:
        y = float(y)
    else:
        y = 0

    z = request.GET.get('z')
    if z is not None and len(z) > 0:
        z = float(z)
    else:
        z = 0

    h = request.GET.get('h')
    if h is not None and len(h) > 0:
        h = float(h)
    else:
        h = 0

    time_period = request.GET.get('time_period')
    if time_period is not None and len(time_period) > 0:
        time_period = float(time_period)
    else:
        time_period = 0

    a = request.GET.get('a')
    if a is not None and len(a) > 0:
        a = float(a)
    else:
        a = 0

    loop_count = request.GET.get('loop_count')
    if loop_count is not None and len(loop_count) > 0:
        loop_count = float(loop_count)
    else:
        loop_count = 0

    b = request.GET.get('b')
    if b is not None and len(b) > 0:
        b = float(b)
    else:
        b = 0

    # Get result from a CPP function
    result = cpp_function.run(prog_choice, method_choice, m, r, v0, th, c,
                              L, C, R, initialTime, finalTime, i0, q0, n,
                              m1, m2, l1, l2, o11, o22, g,
                              p, mu, x, v0,
                              q, vx, vy, vz, Ex, Ey, Ez, Bx, By, Bz,
                              y, z, sigma, rho, beta, h,
                              time_period, a, loop_count,
                              b)

    context = {
        'result': result,
        'm': m,
        'r': r,
        'th': th,
        'V0': v0,
        'c': c,
        'method_choice': method_choice,
        'prog_choice': prog_choice,
        'L': L,
        'C': C,
        'R': R,
        'initialTime': initialTime,
        'finalTime': finalTime,
        'I': i0,
        'Q': q0,
        'n': n,
        'm1': m1,
        'm2': m2,
        'l1': l1,
        'l2': l2,
        'o11': o11,
        'o22': o22,
        'g': g,
        'p': p,
        'mu': mu,
        'x': x,
        'v': v0,
        'q': q,
        'vx': vx,
        'vy': vy,
        'vz': vz,
        'Ex': Ex,
        'Ey': Ey,
        'Ez': Ez,
        'Bx': Bx,
        'By': By,
        'Bz': Bz,
        'y': y,
        'z': z,
        'sigma': sigma,
        'rho': rho,
        'beta': beta,
        'h': h,
        'time_period': time_period,
        'a': a,
        'loop_count': loop_count,
        'b': b,
        'codeFilesList': ['projectile_code', 'lcr_code', 'double_pendulum', 'drag', 'em_oscillations', 'convection'],
    }

    template = loader.get_template('gui.html')
    return HttpResponse(template.render(context, request))


def codeBlocks(request):
    winView = 'CodeBlocks/codeblocks.exe'
    a = subprocess.Popen([winView])
    print(a)
    return HttpResponse('Happy learning!', request)
