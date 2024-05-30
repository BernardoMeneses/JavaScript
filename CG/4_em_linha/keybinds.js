import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function setupLightKeybinds(pointLight, directionalLight1, directionalLight2, fillLight, ambientLight, spotLight1, spotLight2) {
    document.addEventListener('keydown', function(event) {
        switch(event.key) {
            case '1':
                pointLight.visible = !pointLight.visible;
                break;
            case '2':
                directionalLight1.visible = !directionalLight1.visible;
                break;
            case '3':
                directionalLight2.visible = !directionalLight2.visible;
                break;
            case '4':
                fillLight.visible = !fillLight.visible;
                break;
            case '5':
                ambientLight.visible = !ambientLight.visible;
                break;
            case '6':
                spotLight1.visible = !spotLight1.visible;
                break;
            case '7':
                spotLight2.visible = !spotLight2.visible;
                break;
        }
    });
}

export function setupMovementKeybinds(highlightDisk, addDisc, isGameOver) {
    const handler = event => {
        if (isGameOver()) return;

        switch (event.key) {
            case 'ArrowLeft':
                if (highlightDisk.position.x > -3) highlightDisk.position.x -= 1;
                break;
            case 'ArrowRight':
                if (highlightDisk.position.x < 3) highlightDisk.position.x += 1;
                break;
            case ' ':
                addDisc(highlightDisk.position.x + 3);
                break;
            default:
                break;
        }
    };

    document.addEventListener('keydown', handler);

    return () => document.removeEventListener('keydown', handler);
}

export function setupMenuKeybinds(showMenu) {
    document.addEventListener('keydown', event => {
        if (event.key === 'Escape') {
            showMenu();
        }
    });
}
