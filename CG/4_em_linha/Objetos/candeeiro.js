import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createCandeeiro(light, textureURL = './Texturas/cadeeiro.jpg') {
    // Criar o suporte do candeeiro (haste)
    const textureLoader = new THREE.TextureLoader();
    const suporteGeometry = new THREE.CylinderGeometry(0.1, 0.1, 5, 32);
    const suporteMaterial = new THREE.MeshPhongMaterial({ color: 0xBCBCBC });
    const suporte = new THREE.Mesh(suporteGeometry, suporteMaterial);
    suporte.position.set(0, -1, 0); // Ajuste a posição conforme necessário

    // Criar a cúpula do candeeiro

    const candeeiroTexture = textureLoader.load(textureURL)
    const cupulaGeometry = new THREE.ConeGeometry(1, 2, 32);
    const cupulaMaterial = new THREE.MeshPhongMaterial({ map: candeeiroTexture });
    const cupula = new THREE.Mesh(cupulaGeometry, cupulaMaterial);
    cupula.position.set(0, -3, 0); // Ajuste a posição conforme necessário
    cupula.rotation.x = Math.PI; // Inverter a cúpula para apontar para baixo

    // Criar o grupo do candeeiro
    const candeeiroGroup = new THREE.Group();
    candeeiroGroup.add(suporte);
    candeeiroGroup.add(cupula);

    // Adicionar a PointLight existente ao candeeiro
    light.position.set(0, -5.5, 0); // Ajuste a posição da luz dentro da cúpula
    candeeiroGroup.add(light);

    return candeeiroGroup;
}

