import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createPorta(position = { x: 50, y: 0, z: 0 }, textureURL = './Skybox/mesa.png') {
    const textureLoader = new THREE.TextureLoader();
    const portaTexture = textureLoader.load(textureURL);
    const portaMaterial = new THREE.MeshPhongMaterial({ map: portaTexture });
    const portaGeometry = new THREE.BoxGeometry(10, 20, 1);
    const porta = new THREE.Mesh(portaGeometry, portaMaterial);
    porta.position.set(position.x, position.y, position.z);

    // Ajuste a rotação inicial da porta para ficar alinhada de frente para a parede
    porta.rotation.y = Math.PI / 2; // Ajuste conforme necessário para alinhar corretamente

    return porta;
}

export function rotatePortaY(porta, angle = Math.PI / 2, duration = 1000) {
    const startRotation = { y: porta.rotation.y };
    const endRotation = { y: porta.rotation.y + angle };

    new TWEEN.Tween(startRotation)
        .to(endRotation, duration)
        .easing(TWEEN.Easing.Quadratic.Out)
        .onUpdate(() => {
            porta.rotation.y = startRotation.y;
        })
        .start();
}
