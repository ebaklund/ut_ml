#! /usr/bin/env python3

import numpy as np
from vispy import app, scene
from vispy.scene import visuals

# ------------------------------------------------------------
# 1. Create the data grid
# ------------------------------------------------------------
x = np.linspace(-1, 1, 50)
y = np.linspace(-1, 1, 50)
X, Y = np.meshgrid(x, y)

# Initial surface: a simple "bump" function (replace with your own later)
Z = (1 - X**2) * (1 - Y**2) * 0.5

# ------------------------------------------------------------
# 2. Set up the vispy canvas and view
# ------------------------------------------------------------
canvas = scene.SceneCanvas(keys='interactive', size=(800, 600), show=True)
view = canvas.central_widget.add_view()
view.camera = scene.TurntableCamera(up='z', fov=60)  # interactive orbit camera

# ------------------------------------------------------------
# 3. Create the surface visual
# ------------------------------------------------------------
surface = visuals.SurfacePlot(
    x=X, y=Y, z=Z,
    shading='smooth',  # or 'flat', 'wireframe'
    color=(0.5, 0.7, 1, 1),   # RGBA
)
view.add(surface)

# Optional: add axes for orientation
axis = scene.visuals.XYZAxis(parent=view.scene)

# ------------------------------------------------------------
# 4. (Optional) Update function – called every frame
#    You can replace Z with live data here.
# ------------------------------------------------------------
def update(ev):
    global surface, X, Y
    # Example animation: make the surface pulse
    t = ev.elapsed  # time since start
    Z_new = (1 - X**2) * (1 - Y**2) * 0.5 * (1 + 0.3 * np.sin(t * 2.0))
    surface.set_data(z=Z_new)

timer = app.Timer()
timer.connect(update)
timer.start(0.05)  # ~20 FPS – smooth enough

# ------------------------------------------------------------
# 5. Run the application
# ------------------------------------------------------------
if __name__ == '__main__':
    canvas.show()
    app.process_events()                    # force the native window to be realised
    if canvas.size[0] == 0 or canvas.size[1] == 0:
        print("Window failed to appear – check your display environment.")
        print("Is DISPLAY set? Are you on a graphical session?")
        sys.exit(1)
    app.run()
