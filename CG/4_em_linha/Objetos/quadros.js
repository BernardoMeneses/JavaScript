import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createQuadroGroup(imageUrls, positions, rotationY = 0) {
    const frameWidth = 10;
    const frameHeight = 10;
    const frameDepth = 0.5;
    const loader = new THREE.TextureLoader();
    const group = new THREE.Group();
    const frametexture = loader.load('./Skybox/mesa.png')

    positions.forEach((pos, index) => {
        
        const frameGeometry = new THREE.BoxGeometry(frameWidth, frameHeight, frameDepth);
        const frameMaterial = new THREE.MeshPhongMaterial({ map: frametexture});
        const frame = new THREE.Mesh(frameGeometry, frameMaterial);

        const imageUrl = imageUrls[index % imageUrls.length];
        loader.load(imageUrl, (texture) => {
            const pictureGeometry = new THREE.PlaneGeometry(frameWidth - 1, frameHeight - 1);
            const pictureMaterial = new THREE.MeshBasicMaterial({ map: texture });
            const picture = new THREE.Mesh(pictureGeometry, pictureMaterial);

            picture.position.set(0, 0, frameDepth / 2 + 0.01); // Ajuste a posição para garantir que a imagem fique na frente da moldura

            const quadro = new THREE.Group();
            quadro.add(frame);
            quadro.add(picture);
            quadro.position.set(pos.x, pos.y, pos.z);
            quadro.rotation.y = rotationY;

            group.add(quadro);
        });
    });

    return group;
}

export function addQuadroGroupToWall(wall, quadroGroup) {
    wall.add(quadroGroup);
}





